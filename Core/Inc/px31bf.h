#ifndef px31bf_H_
#define px31bf_H_
#endif

//PS Register Setting
#define PX31BF_ADDR 0x1C      //PX31BF I2C Address=0x1C
#define PX31BF_W 0
#define PX31BF_R 1

#define PsDataLow 0x00
#define PsDataHi 0x01

#define DevCtrl 0xF0          //Device Control
#define IntCtrl 0xF1          //Interrupt Control 
#define HaltCtrl 0xF2          //Halt Control  
#define SysCtrl 0xF3          //System Control
#define SwRst 0xF4            //Software Reset
#define IntFlag 0xFE          //Interrupt Flag
#define StatFlag 0xFF         //Status Flag

#define WaitTime 0x4F        //Wait Time         
#define PsCtrl 0x60          //PS Control
#define PsPuw 0x61           //PS Integration Pulse Width
#define PsPuc 0x62           //PS Integration Pulse Count
#define PsDrvCtrl 0x64       //PS Driver Control
#define PsDacCtrl 0x65       //PS DAC Control
#define PsCtCtrl 0x68        //Crosstalk DAC
#define PsCalL 0x69          //Low Byte Digital PS Calibration
#define PsCalH 0x6A          //High Byte Digital PS Calibration
#define PsAlgoCtrl 0x6B      //PS Algorithm control
#define PsThLowL 0x6C        //Low Byte PS Threshold Low
#define PsThLowH 0x6D        //High Byte PS Threshold Low
#define PsThHighL 0x6E       //Low Byte PS Threshold High
#define PsThHighH 0x6F       //High Byte PS Threshold High



enum PX31BF_DevCtrl_value                //Register 0xF9 value
{
    PX31BF_PsEn=1,                         //PS enable/disable bit
};

enum PX31BF_IntCtrl_value                //Register 0xF1 value
{
    PX31BF_PsIntEn=1,
    PX31BF_DataIntEn=0,        	
};

enum PX31BF_HaltCtrl_value               //Register 0xF2 value
{
	PX31BF_PsHalt=0,
	PX31BF_DataHalt=0,
};

enum PX31BF_SysCtrl_value   //Register 0xF3 value
{
	PX31BF_IoFunc=0,
};

enum PX31BF_SwRst_value        //Register 0xF4 value
{
	PX31BF_SwRst_=0xEE,
};

enum PX31BF_IntFlag_value        //Register 0xFE value
{
    PX31BF_PsInt=1,
	PX31BF_DataInt=1,
	PX31BF_PorInt=0,
};

enum PX31BF_StatFlag_value                //Register 0xFF value
{
	PX31BF_PsAmbErr=0,
	PX31BF_Obj=0,
};

enum PX31BF_WaitTime_value                //Register 0x4F value
{
    PX31BF_WaitTime=0x00,
};

enum PX321BF_PsCtrl_value                //Register 0x60 value
{
    PX31BF_PsBits=0,
	PX31BF_PsMean=0,
};

enum PX31BF_PsPuw_value                //Register 0x61 value
{
    PX31BF_PsPuw=0x0B,
};

enum PX31BF_PsPuc_value                //Register 0x62 value
{
    PX31BF_PsPuc=0x02,
};

enum PX31BF_PsDrvCtrl_value            //Register 0x64 value
{
    PX31BF_PsDrv=0x0B,
};

enum PX31BF_PsDacCtrl_value          //Register 0x65 value
{
    PX31BF_PsCtGain=0x01,
};

enum PX31BF_PSCtCtrl_value        //Register 0x68 value for PX31BF ; Register 0x67 value for PX318J
{
    PX31BF_PsCtDac=0x00,
};

enum PX31BF_PsCalL_value             //Register 0x69 value
{
    PX31BF_PsCalL=0x00,
};

enum PX31BF_PsCalH_value             //Register 0x6A value
{
    PX31BF_PsCalH=0x00,
};

enum PX31BF_PsAlgoCtrl_value         //Register 0x6B value
{
    PX31BF_PsPers=0x01,
	PX31BF_PsIntAlgo=1,
	PX31BF_PsWaitAlgo=1,
};

enum PX31BF_PsThLow_value            //Register 0x6C value
{
    PX31BF_PsThLowL=0x00,
};

enum PX31BF_PsThLowH_value         //Register 0x6D value
{
    PX31BF_PsThLowH=0x00,
};

enum PX31BF_PsThHighL_value        //Register 0x6E value
{
    PX31BF_PsThHighL=0xFF,
};

enum PX31BF_PsThHighH_value        //Register 0x6F value
{
    PX31BF_PSThHighH=0xFF,
};






