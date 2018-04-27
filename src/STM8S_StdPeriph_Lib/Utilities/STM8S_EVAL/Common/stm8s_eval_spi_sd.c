/**
  ******************************************************************************
  * @file    stm8s_eval_spi_sd.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    05-February-2018
  * @brief   This file provides a set of functions needed to manage the SPI SD
  *          Card memory mounted on STM8xx-EVAL board (refer to stm8s_eval.h
  *          to know about the boards supporting this memory).
  *          It implements a high level communication layer for read and write
  *          from/to this memory. The needed STM8 hardware resources (SPI and
  *          GPIO) are defined in stm8xx_eval.h file, and the initialization is
  *          performed in SD_LowLevel_Init() function declared in stm8xx_eval.c
  *          file.
  *          You can easily tailor this driver to any other development board,
  *          by just adapting the defines for hardware resources and
  *          SD_LowLevel_Init() function.
  *
  *          +-------------------------------------------------------+
  *          |                     Pin assignment                    |
  *          +-------------------------+---------------+-------------+
  *          |  STM8 SPI Pins          |     SD        |    Pin      |
  *          +-------------------------+---------------+-------------+
  *          | _CS_PIN                 |   ChipSelect  |    1        |
  *          | _MOSI_PIN / MOSI        |   DataIn      |    2        |
  *          |                         |   GND         |    3 (0 V)  |
  *          |                         |   VDD         |    4 (3.3 V)|
  *          | _SCK_PIN / SCLK         |   Clock       |    5        |
  *          |                         |   GND         |    6 (0 V)  |
  *          | _MISO_PIN / MISO        |   DataOut     |    7        |
  *          +-------------------------+---------------+-------------+
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s_eval_spi_sd.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/** @defgroup STM8S_EVAL_SPI_SD_Private_Functions
  * @{
  */

  /**
  * @}
  */

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup STM8_EVAL
  * @{
  */

/** @addtogroup Common
  * @{
  */

/** @addtogroup STM8_EVAL_SPI_SD
  * @brief      This file includes the SD card driver of STM8-EVAL boards.
  * @{
  */

/** @defgroup STM8_EVAL_SPI_SD_Private_Types
  * @{
  */
typedef struct {
  uint8_t r1;
  uint8_t r2;
  uint8_t r3;
  uint8_t r4;
  uint8_t r5;
} SD_CmdAnswer_typedef;

/**
  * @brief  SD ansewer format
  */
typedef enum {
 SD_ANSWER_R1_EXPECTED,
 SD_ANSWER_R1B_EXPECTED,
 SD_ANSWER_R2_EXPECTED,
 SD_ANSWER_R3_EXPECTED,
 SD_ANSWER_R4R5_EXPECTED,
 SD_ANSWER_R7_EXPECTED
}SD_Answer_type;

/**
  * @}
  */


/** @defgroup STM8S_EVAL_SPI_SD_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup STM8S_EVAL_SPI_SD_Private_Macros
  * @{
  */
/**
  * @}
  */


/** @defgroup STM8S_EVAL_SPI_SD_Private_Variables
  * @{
  */
/* flag_SDHC :
      0 : Standard capacity
      1 : High capacity
*/
uint16_t flag_SDHC = 0;
/**
  * @}
  */


/** @defgroup STM8S_EVAL_SPI_SD_Private_Functions
  * @{
  */
static SD_CmdAnswer_typedef SD_SendCmd(uint8_t Cmd, uint32_t Arg, uint8_t Crc, uint8_t Answer);

/**
  * @brief  DeInitializes the SD/SD communication.
  * @param  None
  * @retval None
  */
void SD_DeInit(void)
{
  SD_LowLevel_DeInit();
}

/**
  * @brief  Initializes the SD/SD communication.
  * @param  None
  * @retval The SD Response:
  *         - SD_RESPONSE_FAILURE: Sequence failed
  *         - SD_RESPONSE_NO_ERROR: Sequence succeed
  */
SD_Error SD_Init(void)
{
  uint32_t i = 0;
  /*!< Initialize  */
  SD_LowLevel_Init();

  /*!< SD chip select high */
  SD_CS_HIGH();

  /*!< Send dummy byte 0xFF, 10 times with CS high */
  /*!< Rise CS and MOSI for 80 clocks cycles */
  for (i = 0; i <= 9; i++)
  {
    /*!< Send dummy byte 0xFF */
    SD_WriteByte(SD_DUMMY_BYTE);
  }

  /*------------Put SD in SPI mode--------------*/
  /*!< SD initialized and set to SPI mode properly */
  return (SD_GoIdleState());
}

/**
 * @brief  Detect if SD card is correctly plugged in the memory slot.
 * @param  None
 * @retval Return if SD is detected or not
 */
uint8_t SD_Detect(void)
{
  __IO uint8_t status = SD_PRESENT;

  /*!< Check GPIO to detect SD */
  if (GPIO_ReadInputData(SD_DETECT_GPIO_PORT) & SD_DETECT_PIN)
  {
    status = SD_NOT_PRESENT;
  }
  return status;
}

/**
  * @brief  Returns information about specific card.
  * @param  cardinfo: pointer to a SD_CardInfo structure that contains all SD
  *         card information.
  * @retval The SD Response:
  *         - SD_RESPONSE_FAILURE: Sequence failed
  *         - SD_RESPONSE_NO_ERROR: Sequence succeed
  */
SD_Error SD_GetCardInfo(SD_CardInfo *cardinfo)
{
  SD_Error status = SD_RESPONSE_FAILURE;

  SD_GetCSDRegister(&(cardinfo->SD_csd));
  status = SD_GetCIDRegister(&(cardinfo->SD_cid));
  if(flag_SDHC == 1)
  {
    cardinfo->CardBlockSize = 512;
    cardinfo->CardCapacity = (cardinfo->SD_csd.version.v2.DeviceSize + 1) * cardinfo->CardBlockSize;
  }
  else
  {
    cardinfo->CardCapacity = (cardinfo->SD_csd.version.v1.DeviceSize + 1) ;
    cardinfo->CardCapacity *= (1 << (cardinfo->SD_csd.version.v1.DeviceSizeMul + 2));
    cardinfo->CardBlockSize = 1 << (cardinfo->SD_csd.RdBlockLen);
    cardinfo->CardCapacity *= cardinfo->CardBlockSize;
  }
  /*!< Returns the reponse */
  return status;
}

/**
  * @brief  Reads a block of data from the SD.
  * @param  pBuffer: pointer to the buffer that receives the data read from the
  *                  SD.
  * @param  ReadAddr: SD's internal address to read from.
  * @param  BlockSize: the SD card Data block size.
  * @retval The SD Response:
  *         - SD_RESPONSE_FAILURE: Sequence failed
  *         - SD_RESPONSE_NO_ERROR: Sequence succeed
  */
SD_Error SD_ReadBlock(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t BlockSize)
{
  uint32_t i = 0;
  SD_Error rvalue = SD_RESPONSE_FAILURE;
  SD_CmdAnswer_typedef response;
  /*!< SD chip select low */
  SD_CS_LOW();

  /*!< Send CMD17 (SD_CMD_READ_SINGLE_BLOCK) to read one block */
  response = SD_SendCmd(SD_CMD_READ_SINGLE_BLOCK, ReadAddr/(flag_SDHC == 1 ? BlockSize: 1), 0xFF, SD_ANSWER_R1_EXPECTED);

  /*!< Check if the SD acknowledged the read block command: R1 response (0x00: no errors) */
  if (response.r1 == SD_RESPONSE_NO_ERROR)
  {
    /*!< Now look for the data token to signify the start of the data */
    if (!SD_GetResponse(SD_START_DATA_SINGLE_BLOCK_READ))
    {
      /*!< Read the SD block data : read NumByteToRead data */
      for (i = 0; i < BlockSize; i++)
      {
        /*!< Save the received data */
        *pBuffer = SD_ReadByte();

        /*!< Point to the next location where the byte read will be saved */
        pBuffer++;
      }
      /*!< Get CRC bytes (not really needed by us, but required by SD) */
      SD_ReadByte();
      SD_ReadByte();
      /*!< Set response value to success */
      rvalue = SD_RESPONSE_NO_ERROR;
    }
  }
  /*!< SD chip select high */
  SD_CS_HIGH();

  /*!< Send dummy byte: 8 Clock pulses of delay */
  SD_WriteByte(SD_DUMMY_BYTE);

  /*!< Returns the reponse */
  return rvalue;
}

/**
  * @brief  Reads multiple block of data from the SD.
  * @param  pBuffer: pointer to the buffer that receives the data read from the
  *                  SD.
  * @param  ReadAddr: SD's internal address to read from.
  * @param  BlockSize: the SD card Data block size.
  * @param  NumberOfBlocks: number of blocks to be read.
  * @retval The SD Response:
  *         - SD_RESPONSE_FAILURE: Sequence failed
  *         - SD_RESPONSE_NO_ERROR: Sequence succeed
  */
SD_Error SD_ReadMultiBlocks(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t BlockSize, uint32_t NumberOfBlocks)
{
  uint32_t i = 0, Offset = 0;
  SD_Error rvalue = SD_RESPONSE_FAILURE;
  SD_CmdAnswer_typedef response;

  /*!< SD chip select low */
  SD_CS_LOW();

  /*!< Data transfer */
  while (NumberOfBlocks--)
  {
    /*!< Send CMD17 (SD_CMD_READ_SINGLE_BLOCK) to read one block */
    response = SD_SendCmd(SD_CMD_READ_SINGLE_BLOCK, (ReadAddr + Offset)/(flag_SDHC == 1 ?BlockSize: 1), 0xFF, SD_ANSWER_R1_EXPECTED);
    /*!< Check if the SD acknowledged the read block command: R1 response (0x00: no errors) */
    if (response.r1 != SD_RESPONSE_NO_ERROR)
    {
      return  SD_RESPONSE_FAILURE;
    }
    /*!< Now look for the data token to signify the start of the data */
    if (!SD_GetResponse(SD_START_DATA_SINGLE_BLOCK_READ))
    {
      /*!< Read the SD block data : read NumByteToRead data */
      for (i = 0; i < BlockSize; i++)
      {
        /*!< Read the pointed data */
        *pBuffer = SD_ReadByte();
        /*!< Point to the next location where the byte read will be saved */
        pBuffer++;
      }
      /*!< Set next read address*/
      Offset += 512;
      /*!< get CRC bytes (not really needed by us, but required by SD) */
      SD_ReadByte();
      SD_ReadByte();
      /*!< Set response value to success */
      rvalue = SD_RESPONSE_NO_ERROR;
    }
    else
    {
      /*!< Set response value to failure */
      rvalue = SD_RESPONSE_FAILURE;
    }
  }
  /*!< SD chip select high */
  SD_CS_HIGH();
  /*!< Send dummy byte: 8 Clock pulses of delay */
  SD_WriteByte(SD_DUMMY_BYTE);
  /*!< Returns the reponse */
  return rvalue;
}

/**
  * @brief  Writes a block on the SD
  * @param  pBuffer: pointer to the buffer containing the data to be written on
  *                  the SD.
  * @param  WriteAddr: address to write on.
  * @param  BlockSize: the SD card Data block size.
  * @retval The SD Response:
  *         - SD_RESPONSE_FAILURE: Sequence failed
  *         - SD_RESPONSE_NO_ERROR: Sequence succeed
  */
SD_Error SD_WriteBlock(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t BlockSize)
{
  uint32_t i = 0;
  SD_Error rvalue = SD_RESPONSE_FAILURE;

  SD_CmdAnswer_typedef response;
  /*!< SD chip select low */
  SD_CS_LOW();

  /*!< Send CMD17 (SD_CMD_READ_SINGLE_BLOCK) to read one block */
  response = SD_SendCmd(SD_CMD_WRITE_SINGLE_BLOCK, WriteAddr/(flag_SDHC == 1 ? BlockSize: 1), 0xFF, SD_ANSWER_R1_EXPECTED);

  /*!< Check if the SD acknowledged the read block command: R1 response (0x00: no errors) */
  if (response.r1 == SD_RESPONSE_NO_ERROR)
  {
    /*!< Send a dummy byte */
    SD_WriteByte(SD_DUMMY_BYTE);

    /*!< Send the data token to signify the start of the data */
    SD_WriteByte(0xFE);

    /*!< Write the block data to SD : write count data by block */
    for (i = 0; i < BlockSize; i++)
    {
      /*!< Send the pointed byte */
      SD_WriteByte(*pBuffer);
      /*!< Point to the next location where the byte read will be saved */
      pBuffer++;
    }
    /*!< Put CRC bytes (not really needed by us, but required by SD) */
    SD_ReadByte();
    SD_ReadByte();
    /*!< Read data response */
    if (SD_GetDataResponse() == SD_DATA_OK)
    {
      rvalue = SD_RESPONSE_NO_ERROR;
    }
  }
  /*!< SD chip select high */
  SD_CS_HIGH();
  /*!< Send dummy byte: 8 Clock pulses of delay */
  SD_WriteByte(SD_DUMMY_BYTE);

  /*!< Returns the reponse */
  return rvalue;
}

/**
  * @brief  Writes many blocks on the SD
  * @param  pBuffer: pointer to the buffer containing the data to be written on
  *                  the SD.
  * @param  WriteAddr: address to write on.
  * @param  BlockSize: the SD card Data block size.
  * @param  NumberOfBlocks: number of blocks to be written.
  * @retval The SD Response:
  *         - SD_RESPONSE_FAILURE: Sequence failed
  *         - SD_RESPONSE_NO_ERROR: Sequence succeed
  */
SD_Error SD_WriteMultiBlocks(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t BlockSize, uint32_t NumberOfBlocks)
{
  uint32_t i = 0, Offset = 0;
  SD_Error rvalue = SD_RESPONSE_FAILURE;
  SD_CmdAnswer_typedef response;
  /*!< SD chip select low */
  SD_CS_LOW();

  response = SD_SendCmd(SD_CMD_SET_BLOCKLEN, BlockSize, 0xFF, SD_ANSWER_R1_EXPECTED);
  /*!< SD chip select high */
  SD_CS_HIGH();
  /*!< Send dummy byte: 8 Clock pulses of delay */
  SD_WriteByte(SD_DUMMY_BYTE);

  if ( response.r1 != SD_RESPONSE_NO_ERROR)
  {
    return SD_RESPONSE_FAILURE;
  }

  /*!< Data transfer */
  while (NumberOfBlocks--)
  {
    /*!< Send CMD24 (SD_CMD_WRITE_SINGLE_BLOCK) to write blocks */
    response = SD_SendCmd(SD_CMD_WRITE_SINGLE_BLOCK, (WriteAddr + Offset)/(flag_SDHC == 1 ? BlockSize: 1), 0xFF, SD_ANSWER_R1_EXPECTED);
    /*!< Check if the SD acknowledged the write block command: R1 response (0x00: no errors) */
    if (response.r1 != SD_RESPONSE_NO_ERROR)
    {
      return  SD_RESPONSE_FAILURE;
    }
    /*!< Send dummy byte */
    SD_WriteByte(SD_DUMMY_BYTE);
    SD_WriteByte(SD_DUMMY_BYTE);
    /*!< Send the data token to signify the start of the data */
    SD_WriteByte(SD_START_DATA_SINGLE_BLOCK_WRITE);
    /*!< Write the block data to SD : write count data by block */
    for (i = 0; i < BlockSize; i++)
    {
      /*!< Send the pointed byte */
      SD_WriteByte(*pBuffer);
      /*!< Point to the next location where the byte read will be saved */
      pBuffer++;
    }
    /*!< Set next write address */
    Offset += 512;
    /*!< Put CRC bytes (not really needed by us, but required by SD) */
    SD_ReadByte();
    SD_ReadByte();
    /*!< Read data response */
    if (SD_GetDataResponse() == SD_DATA_OK)
    {
      /*!< Set response value to success */
      rvalue = SD_RESPONSE_NO_ERROR;
    }
    else
    {
      /*!< Set response value to failure */
      rvalue = SD_RESPONSE_FAILURE;
    }
  }
  /*!< SD chip select high */
  SD_CS_HIGH();
  /*!< Send dummy byte: 8 Clock pulses of delay */
  SD_WriteByte(SD_DUMMY_BYTE);
  /*!< Returns the reponse */
  return rvalue;
}

/**
  * @brief  Read the CSD card register.
  *         Reading the contents of the CSD register in SPI mode is a simple
  *         read-block transaction.
  * @param  SD_csd: pointer on an SCD register structure
  * @retval The SD Response:
  *         - SD_RESPONSE_FAILURE: Sequence failed
  *         - SD_RESPONSE_NO_ERROR: Sequence succeed
  */
SD_Error SD_GetCSDRegister(SD_CSD* SD_csd)
{
  uint32_t i = 0;
  SD_Error rvalue = SD_RESPONSE_FAILURE;
  SD_CmdAnswer_typedef response;
  uint8_t CSD_Tab[16];

  /*!< SD chip select low */
  SD_CS_LOW();
  /* Send CMD9 (CSD register) or CMD10(CSD register) and Wait for response in the R1 format (0x00 is no errors) */
  response = SD_SendCmd(SD_CMD_SEND_CSD, 0, 0xFF, SD_ANSWER_R1_EXPECTED);
  /*!< Wait for response in the R1 format (0x00 is no errors) */
  if (response.r1 == SD_RESPONSE_NO_ERROR)
  {
    if (!SD_GetResponse(SD_START_DATA_SINGLE_BLOCK_READ))
    {
      for (i = 0; i < 16; i++)
      {
        /*!< Store CSD register value on CSD_Tab */
        CSD_Tab[i] = SD_ReadByte();
      }
    }
    /*!< Get CRC bytes (not really needed by us, but required by SD) */
    SD_WriteByte(SD_DUMMY_BYTE);
    SD_WriteByte(SD_DUMMY_BYTE);
    /*!< Set response value to success */
    rvalue = SD_RESPONSE_NO_ERROR;
  }


  /*!< Byte 0 */
  SD_csd->CSDStruct = (CSD_Tab[0] & 0xC0) >> 6;
  SD_csd->Reserved1 = CSD_Tab[0] & 0x3F;

  /*!< Byte 1 */
  SD_csd->TAAC = CSD_Tab[1];

  /*!< Byte 2 */
  SD_csd->NSAC = CSD_Tab[2];

  /*!< Byte 3 */
  SD_csd->MaxBusClkFrec = CSD_Tab[3];

  /*!< Byte 4 */
  SD_csd->CardComdClasses = CSD_Tab[4] << 4;

  /*!< Byte 5 */
  SD_csd->CardComdClasses |= (CSD_Tab[5] & 0xF0) >> 4;
  SD_csd->RdBlockLen = CSD_Tab[5] & 0x0F;

  /*!< Byte 6 */
  SD_csd->PartBlockRead = (CSD_Tab[6] & 0x80) >> 7;
  SD_csd->WrBlockMisalign = (CSD_Tab[6] & 0x40) >> 6;
  SD_csd->RdBlockMisalign = (CSD_Tab[6] & 0x20) >> 5;
  SD_csd->DSRImpl = (CSD_Tab[6] & 0x10) >> 4;
  SD_csd->Reserved2 = 0; /*!< Reserved */

  if(flag_SDHC == 0)
  {
    SD_csd->version.v1.Reserved1 = ((CSD_Tab[6] & 0x0C) >> 2);

    SD_csd->version.v1.DeviceSize =  ((CSD_Tab[6] & 0x03) << 10)
                                   |  (CSD_Tab[7] << 2)
                                   | ((CSD_Tab[8] & 0xC0) >> 6);
    SD_csd->version.v1.MaxRdCurrentVDDMin = (CSD_Tab[8] & 0x38) >> 3;
    SD_csd->version.v1.MaxRdCurrentVDDMax = (CSD_Tab[8] & 0x07);
    SD_csd->version.v1.MaxWrCurrentVDDMin = (CSD_Tab[9] & 0xE0) >> 5;
    SD_csd->version.v1.MaxWrCurrentVDDMax = (CSD_Tab[9] & 0x1C) >> 2;
    SD_csd->version.v1.DeviceSizeMul = ((CSD_Tab[9] & 0x03) << 1)
                                      |((CSD_Tab[10] & 0x80) >> 7);
  }
  else
  {
    SD_csd->version.v2.Reserved1 = ((CSD_Tab[6] & 0x0F) << 2) | ((CSD_Tab[7] & 0xC0) >> 6);
    SD_csd->version.v2.DeviceSize= ((CSD_Tab[7] & 0x3F) * 0x10000) | (CSD_Tab[8] << 8) | CSD_Tab[9];
    SD_csd->version.v2.Reserved2 = ((CSD_Tab[10] & 0x80) >> 8);
  }

  SD_csd->EraseSingleBlockEnable = (CSD_Tab[10] & 0x40) >> 6;
  SD_csd->EraseSectorSize   = ((CSD_Tab[10] & 0x3F) << 1)
                              |((CSD_Tab[11] & 0x80) >> 7);

  /*!< Byte 11 */
  SD_csd->WrProtectGrSize = (CSD_Tab[11] & 0x7F);

  /*!< Byte 12 */
  SD_csd->WrProtectGrEnable = (CSD_Tab[12] & 0x80) >> 7;
  SD_csd->Reserved2         = (CSD_Tab[12] & 0x60) >> 5;
  SD_csd->WrSpeedFact       = (CSD_Tab[12] & 0x1C) >> 2;

  /*!< Byte 13 */
  SD_csd->MaxWrBlockLen     = ((CSD_Tab[12] & 0x03) << 2)
                              |((CSD_Tab[13] & 0xC0) >> 6);
  SD_csd->WriteBlockPartial = (CSD_Tab[13] & 0x20) >> 5;
  SD_csd->Reserved3         = (CSD_Tab[13] & 0x1F);

  /*!< Byte 14 */
  SD_csd->FileFormatGrouop = (CSD_Tab[14] & 0x80) >> 7;
  SD_csd->CopyFlag         = (CSD_Tab[14] & 0x40) >> 6;
  SD_csd->PermWrProtect    = (CSD_Tab[14] & 0x20) >> 5;
  SD_csd->TempWrProtect    = (CSD_Tab[14] & 0x10) >> 4;
  SD_csd->FileFormat       = (CSD_Tab[14] & 0x0C) >> 2;
  SD_csd->Reserved4        = (CSD_Tab[14] & 0x03);

  /*!< Byte 15 */
  SD_csd->crc = (CSD_Tab[15] & 0xFE) >> 1;
  SD_csd->Reserved4 = 1;

  /*!< SD chip select high */
  SD_CS_HIGH();
  /*!< Send dummy byte: 8 Clock pulses of delay */
  SD_WriteByte(SD_DUMMY_BYTE);

  /*!< Return the reponse */
  return rvalue;
}

/**
  * @brief  Read the CID card register.
  *         Reading the contents of the CID register in SPI mode is a simple
  *         read-block transaction.
  * @param  SD_cid: pointer on an CID register structure
  * @retval The SD Response:
  *         - SD_RESPONSE_FAILURE: Sequence failed
  *         - SD_RESPONSE_NO_ERROR: Sequence succeed
  */
SD_Error SD_GetCIDRegister(SD_CID* SD_cid)
{
  uint32_t i = 0;
  SD_Error rvalue = SD_RESPONSE_FAILURE;
  uint8_t CID_Tab[16];
  SD_CmdAnswer_typedef response;
  /*!< SD chip select low */
  SD_CS_LOW();

  /* Send CMD10 (CID register) and Wait for response in the R1 format (0x00 is no errors) */
  response = SD_SendCmd(SD_CMD_SEND_CID, 0, 0xFF, SD_ANSWER_R1_EXPECTED);

  /*!< Wait for response in the R1 format (0x00 is no errors) */
  if (response.r1 == SD_RESPONSE_NO_ERROR)
  {
    if (!SD_GetResponse(SD_START_DATA_SINGLE_BLOCK_READ))
    {
      /*!< Store CID register value on CID_Tab */
      for (i = 0; i < 16; i++)
      {
        CID_Tab[i] = SD_ReadByte();
      }
    }
    /*!< Get CRC bytes (not really needed by us, but required by SD) */
    SD_WriteByte(SD_DUMMY_BYTE);
    SD_WriteByte(SD_DUMMY_BYTE);
    /*!< Set response value to success */
    rvalue = SD_RESPONSE_NO_ERROR;
  }
  else
  {
    /*!< Set response value to failure */
    rvalue = SD_RESPONSE_FAILURE;
  }

  /*!< Byte 0 */
  SD_cid->ManufacturerID = CID_Tab[0];

  /*!< Byte 1 */
  SD_cid->OEM_AppliID = CID_Tab[1] << 8;

  /*!< Byte 2 */
  SD_cid->OEM_AppliID |= CID_Tab[2];

  /*!< Byte 3 */
  SD_cid->ProdName1 = CID_Tab[3] * 0x1000000;

  /*!< Byte 4 */
  SD_cid->ProdName1 |= CID_Tab[4] * 0x10000;

  /*!< Byte 5 */
  SD_cid->ProdName1 |= CID_Tab[5] << 8;

  /*!< Byte 6 */
  SD_cid->ProdName1 |= CID_Tab[6];

  /*!< Byte 7 */
  SD_cid->ProdName2 = CID_Tab[7];

  /*!< Byte 8 */
  SD_cid->ProdRev = CID_Tab[8];

  /*!< Byte 9 */
  SD_cid->ProdSN = CID_Tab[9] *  0x1000000;

  /*!< Byte 10 */
  SD_cid->ProdSN |= CID_Tab[10] * 0x10000;

  /*!< Byte 11 */
  SD_cid->ProdSN |= CID_Tab[11] << 8;

  /*!< Byte 12 */
  SD_cid->ProdSN |= CID_Tab[12];

  /*!< Byte 13 */
  SD_cid->Reserved1 |= (CID_Tab[13] & 0xF0) >> 4;
  SD_cid->ManufactDate = (CID_Tab[13] & 0x0F) << 8;

  /*!< Byte 14 */
  SD_cid->ManufactDate |= CID_Tab[14];

  /*!< Byte 15 */
  SD_cid->CID_CRC = (CID_Tab[15] & 0xFE) >> 1;
  SD_cid->Reserved2 = 1;

  /*!< SD chip select high */
  SD_CS_HIGH();
  /*!< Send dummy byte: 8 Clock pulses of delay */
  SD_WriteByte(SD_DUMMY_BYTE);

  /*!< Return the reponse */
  return rvalue;
}

/**
  * @brief  Send 5 bytes command to the SD card.
  * @param  Cmd: The user expected command to send to SD card.
  * @param  Arg: The command argument.
  * @param  Crc: The CRC.
  * @retval None
  */
static SD_CmdAnswer_typedef SD_SendCmd(uint8_t Cmd, uint32_t Arg, uint8_t Crc, uint8_t Answer)
{
  uint32_t i = 0x00;
  SD_CmdAnswer_typedef retr = {0xFF, 0xFF , 0xFF, 0xFF, 0xFF};
  uint8_t Frame[6];

  Frame[0] = (Cmd | 0x40); /*!< Construct byte 1 */

  Frame[1] = (uint8_t)(Arg >> 24); /*!< Construct byte 2 */

  Frame[2] = (uint8_t)(Arg >> 16); /*!< Construct byte 3 */

  Frame[3] = (uint8_t)(Arg >> 8); /*!< Construct byte 4 */

  Frame[4] = (uint8_t)(Arg); /*!< Construct byte 5 */

  Frame[5] = (Crc | 0x01); /*!< Construct CRC: byte 6 */

  SD_CS_LOW();

  for (i = 0; i < 6; i++)
  {
    SD_WriteByte(Frame[i]); /*!< Send the Cmd bytes */
  }

switch(Answer)
  {
  case SD_ANSWER_R1_EXPECTED :
    retr.r1 = SD_ReadData();
    break;
  case SD_ANSWER_R1B_EXPECTED :
    retr.r1 = SD_ReadData();
    retr.r2 = SD_WriteByte(SD_DUMMY_BYTE);
    /* Set CS High */
    SD_CS_HIGH();

    /* Set CS Low */
    SD_CS_LOW();

    /* Wait IO line return 0xFF */
    while (SD_WriteByte(SD_DUMMY_BYTE) != 0xFF);
    break;
  case SD_ANSWER_R2_EXPECTED :
    retr.r1 = SD_ReadData();
    retr.r2 = SD_WriteByte(SD_DUMMY_BYTE);
    break;
  case SD_ANSWER_R3_EXPECTED :
  case SD_ANSWER_R7_EXPECTED :
    retr.r1 = SD_ReadData();
    retr.r2 = SD_WriteByte(SD_DUMMY_BYTE);
    retr.r3 = SD_WriteByte(SD_DUMMY_BYTE);
    retr.r4 = SD_WriteByte(SD_DUMMY_BYTE);
    retr.r5 = SD_WriteByte(SD_DUMMY_BYTE);
    break;
  default :
    break;
  }
  return retr;
}

/**
  * @brief  Get SD card data response.
  * @param  None
  * @retval The SD status: Read data response xxx0<status>1
  *         - status 010: Data accepted
  *         - status 101: Data rejected due to a crc error
  *         - status 110: Data rejected due to a Write error.
  *         - status 111: Data rejected due to other error.
  */
uint8_t SD_GetDataResponse(void)
{
  uint32_t i = 0;
  uint8_t response = 0, rvalue = 0;

  while (i <= 64)
  {
    /*!< Read response */
    response = SD_ReadByte();
    /*!< Mask unused bits */
    response &= 0x1F;
    switch (response)
    {
      case SD_DATA_OK:
      {
        rvalue = SD_DATA_OK;
        break;
      }
      case SD_DATA_CRC_ERROR:
        return SD_DATA_CRC_ERROR;
      case SD_DATA_WRITE_ERROR:
        return SD_DATA_WRITE_ERROR;
      default:
      {
        rvalue = SD_DATA_OTHER_ERROR;
        break;
      }
    }
    /*!< Exit loop in case of data ok */
    if (rvalue == SD_DATA_OK)
      break;
    /*!< Increment loop counter */
    i++;
  }

  /*!< Wait null data */
  while (SD_ReadByte() == 0);

  /*!< Return response */
  return response;
}

/**
  * @brief  Returns the SD response.
  * @param  None
  * @retval The SD Response:
  *         - SD_RESPONSE_FAILURE: Sequence failed
  *         - SD_RESPONSE_NO_ERROR: Sequence succeed
  */
SD_Error SD_GetResponse(uint8_t Response)
{
  uint32_t Count = 0xFFF;

  /* Check if response is got or a timeout is happen */
  while ((SD_ReadByte() != Response) && Count)
  {
    Count--;
  }

  if (Count == 0)
  {
    /* After time out */
    return SD_RESPONSE_FAILURE;
  }
  else
  {
    /* Right response got */
    return SD_RESPONSE_NO_ERROR;
  }
}

/**
  * @brief  Returns the SD status.
  * @param  None
  * @retval The SD status.
  */
uint16_t SD_GetStatus(void)
{
  SD_CmdAnswer_typedef retr;
  /*!< SD chip select low */
  SD_CS_LOW();

  /*!< Send CMD13 (SD_SEND_STATUS) to get SD status */
  retr = SD_SendCmd(SD_CMD_SEND_STATUS, 0, 0xFF, SD_ANSWER_R2_EXPECTED);

  /*!< SD chip select high */
  SD_CS_HIGH();

  /*!< Send dummy byte 0xFF */
  SD_WriteByte(SD_DUMMY_BYTE);

  /* Find SD status according to card state */
  if(( retr.r1 == SD_RESPONSE_NO_ERROR) && ( retr.r2 == SD_RESPONSE_NO_ERROR))
  {
    return SD_RESPONSE_NO_ERROR;
  }

  return SD_RESPONSE_FAILURE;
}

/**
  * @brief  Put SD in Idle state.
  * @param  None
  * @retval The SD Response:
  *         - SD_RESPONSE_FAILURE: Sequence failed
  *         - SD_RESPONSE_NO_ERROR: Sequence succeed
  */
SD_Error SD_GoIdleState(void)
{
  SD_CmdAnswer_typedef response;
  __IO uint8_t counter = 0;


  do
  {

    /*!< Send CMD0 (SD_CMD_GO_IDLE_STATE) to put SD in SPI mode */
    response = SD_SendCmd(SD_CMD_GO_IDLE_STATE, 0, 0x95, SD_ANSWER_R1_EXPECTED);

    /*!< SD chip select high */
    SD_CS_HIGH();

    /*!< Send Dummy byte 0xFF */
    SD_WriteByte(SD_DUMMY_BYTE);

    if(counter >= 100)
    {
      return SD_RESPONSE_FAILURE;
    }
    counter ++;
  }
  while(response.r1 != SD_IN_IDLE_STATE);

  /*----------Activates the card initialization process-----------*/

  /*!< Send CMD1 (Activates the card process) until response equal to 0x0 */
  response = SD_SendCmd(SD_CMD_SEND_IF_COND, 0x1AA, 0x87, SD_ANSWER_R7_EXPECTED);

  /*!< SD chip select high */
  SD_CS_HIGH();

  /*!< Send Dummy byte 0xFF */
  SD_WriteByte(SD_DUMMY_BYTE);

  if((response.r1  & SD_ILLEGAL_COMMAND) == SD_ILLEGAL_COMMAND)
  {
    /* initialise card V1 */
    do
    {
      /* initialise card V1 */
      /* Send CMD55 (SD_CMD_APP_CMD) before any ACMD command: R1 response (0x00: no errors) */
      response = SD_SendCmd(SD_CMD_APP_CMD, 0x00000000, 0xFF, SD_ANSWER_R1_EXPECTED);
      SD_CS_HIGH();
      SD_WriteByte(SD_DUMMY_BYTE);

      /* Send ACMD41 (SD_CMD_SD_APP_OP_COND) to initialize SDHC or SDXC cards: R1 response (0x00: no errors) */
      response = SD_SendCmd(SD_CMD_SD_APP_OP_COND, 0x00000000, 0xFF, SD_ANSWER_R1_EXPECTED);
      SD_CS_HIGH();
      SD_WriteByte(SD_DUMMY_BYTE);
    }
    while(response.r1 == SD_IN_IDLE_STATE);
    flag_SDHC = 0;
  }
  else if(response.r1 == SD_IN_IDLE_STATE)
  {
      /* initialise card V2 */
    do {

      /* Send CMD55 (SD_CMD_APP_CMD) before any ACMD command: R1 response (0x00: no errors) */
      response = SD_SendCmd(SD_CMD_APP_CMD, 0, 0xFF, SD_ANSWER_R1_EXPECTED);
      SD_CS_HIGH();
      SD_WriteByte(SD_DUMMY_BYTE);

      /* Send ACMD41 (SD_CMD_SD_APP_OP_COND) to initialize SDHC or SDXC cards: R1 response (0x00: no errors) */
      response = SD_SendCmd(SD_CMD_SD_APP_OP_COND, 0x40000000, 0xFF, SD_ANSWER_R1_EXPECTED);
      SD_CS_HIGH();
      SD_WriteByte(SD_DUMMY_BYTE);
    }
    while(response.r1 == SD_IN_IDLE_STATE);

    if((response.r1 & SD_ILLEGAL_COMMAND) == SD_ILLEGAL_COMMAND)
    {
      do {
        /* Send CMD55 (SD_CMD_APP_CMD) before any ACMD command: R1 response (0x00: no errors) */
        response = SD_SendCmd(SD_CMD_APP_CMD, 0, 0xFF, SD_ANSWER_R1_EXPECTED);
        SD_CS_HIGH();
        SD_WriteByte(SD_DUMMY_BYTE);
        if(response.r1 != SD_IN_IDLE_STATE)
        {
          return SD_RESPONSE_FAILURE;
        }
        /* Send ACMD41 (SD_CMD_SD_APP_OP_COND) to initialize SDHC or SDXC cards: R1 response (0x00: no errors) */
        response = SD_SendCmd(SD_CMD_SD_APP_OP_COND, 0x00000000, 0xFF, SD_ANSWER_R1_EXPECTED);
        SD_CS_HIGH();
        SD_WriteByte(SD_DUMMY_BYTE);
      }
      while(response.r1 == SD_IN_IDLE_STATE);
    }

    /* Send CMD58 (SD_CMD_READ_OCR) to initialize SDHC or SDXC cards: R3 response (0x00: no errors) */
    response = SD_SendCmd(SD_CMD_READ_OCR, 0x00000000, 0xFF, SD_ANSWER_R3_EXPECTED);
    SD_CS_HIGH();
    SD_WriteByte(SD_DUMMY_BYTE);
    if(response.r1 != SD_RESPONSE_NO_ERROR)
    {
      return SD_RESPONSE_FAILURE;
    }
    flag_SDHC = (response.r2 & 0x40) >> 6;
  }
  else
  {
    return SD_RESPONSE_FAILURE;
  }

  return SD_RESPONSE_NO_ERROR;
}

/**
  * @brief  Write a byte on the SD.
  * @param  Data: byte to send.
  * @retval None
  */
uint8_t SD_WriteByte(uint8_t Data)
{
  /*!< Wait until the transmit buffer is empty */
  while(SPI_GetFlagStatus(SPI_FLAG_TXE) == RESET)
  {
  }

  /*!< Send the byte */
  SPI_SendData(Data);

  /*!< Wait to receive a byte*/
  while(SPI_GetFlagStatus(SPI_FLAG_RXNE) == RESET)
  {
  }

  /*!< Return the byte read from the SPI bus */
  return SPI_ReceiveData();
}

/**
  * @brief  Read a byte from the SD.
  * @param  None
  * @retval The received byte.
  */
uint8_t SD_ReadByte(void)
{
  uint8_t Data = 0;

  /*!< Wait until the transmit buffer is empty */
  while (SPI_GetFlagStatus(SPI_FLAG_TXE) == RESET)
  {
  }
  /*!< Send the byte */
  SPI_SendData(SD_DUMMY_BYTE);

  /*!< Wait until a data is received */
  while (SPI_GetFlagStatus(SPI_FLAG_RXNE) == RESET)
  {
  }
  /*!< Get the received data */
  Data = SPI_ReceiveData();

  /*!< Return the shifted data */
  return Data;
}

/**
  * @brief  Waits a data until a value different from SD_DUMMY_BITE
  * @param  None
  * @retval the value read
  */
uint8_t SD_ReadData(void)
{
  uint8_t timeout = 0x08;
  uint8_t readvalue;

  /* Check if response is got or a timeout is happen */
  do {
    readvalue = SD_WriteByte(SD_DUMMY_BYTE);
    timeout--;

  }while ((readvalue == SD_DUMMY_BYTE) && timeout);

  /* Right response got */
  return readvalue;
}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
