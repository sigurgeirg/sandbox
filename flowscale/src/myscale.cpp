#include "../inc/myscale.h"


MyScale::MyScale(QObject *parent) :
    QThread(parent)
{
    modbusConnected = false;
    mbCommand[0] = 0;
    commandRegister = 5;
    statusRegister = 6;
    sampleWeightForCalibrationL = 37;
    netDisplay = 7;
    semiAutomaticZero = 8;
    grossDisplay = 9;
    zeroSettingForCalibration = 100;
    sampleWeightStorage = 101;

    readFromRegister = statusRegister;
    weightGROSSorNET[0] = netDisplay; // Default NET weight

    statusRegisterBinaryTempValue = new int[16];
    statusRegisterBinaryReturnValue = new int[16];
}


MyScale::~MyScale()
{
    //
    delete statusRegisterBinaryTempValue;
    delete statusRegisterBinaryReturnValue;
}


int* MyScale::statusRegisterBinary(uint16_t number[]) {

    uint16_t remainder=0, i=0, decimal=number[0];

    do {
        remainder = decimal%2;
        decimal = decimal/2;
        statusRegisterBinaryTempValue[i] = remainder;
        i = i+1;

    } while(decimal>0);

    return statusRegisterBinaryTempValue;
}


void MyScale::connectToSlaveDevice() {

    try {

        ctx = modbus_new_rtu("/dev/ttyUSB0", 38400, 'N', 8, 1);
        setslave = modbus_set_slave(ctx, 0x01);

        if (ctx == NULL)
        {
            qDebug() << "Unable to create the libmodbus context";
            modbus_free(ctx);
        }
        else
            qDebug() << "Creation successful";

        if (setslave == 0)
        {
            qDebug() << "Able to set slave successfully, value : " << setslave;
        }
        else
        {
            qDebug() << "Unable to set slave, value: " << setslave;
            modbus_free(ctx);
        }

        if (modbus_connect(ctx) == -1)
        {
            qDebug() << "Connection failed";
            modbus_free(ctx);
        }
        else
        {
            qDebug() << "Connection successful " << modbus_connect(ctx);
            modbusConnected = true;
            qDebug() << "ModBus is Connected";
            start();
        }
    }
        catch(...) {
    }
}


void MyScale::disconnectFromSlaveDevice() {
    
    try
    {
        modbusConnected = false;

        if (modbus_connect(ctx) == -1) {
            modbus_free(ctx);
        }

        modbus_close(ctx);
        qDebug() << "ModBus is Disconnected";
        //modbus_free(ctx); //This function-call causes segfault if activated here.
    }
    catch(...)
    {
    }
}


void MyScale::toggleWriteToLoadcell(bool checked) {
    
    if(checked == true)
        writeToLoadcell = true;
    else
        writeToLoadcell = false;
}


void MyScale::calibrateZERO() {
    
    writeToRegister = commandRegister;
    mbCommand[0] = zeroSettingForCalibration;
}


void MyScale::calibrateWEIGHT(int calibrationWeight) {

    writeToRegister = sampleWeightForCalibrationL;
    mbCommand[0] = calibrationWeight;
}


void MyScale::storeCalibrationWEIGHT() {
    
    writeToRegister = commandRegister;
    mbCommand[0] = sampleWeightStorage;
}


void MyScale::semiAutoZERO() {
    
    writeToRegister = commandRegister;
    mbCommand[0] = semiAutomaticZero;
}


void MyScale::grossWeight() {
    
    writeToRegister = commandRegister;
    mbCommand[0] = grossDisplay;
}


void MyScale::netWeight() {
    
    writeToRegister = commandRegister;
    mbCommand[0] = netDisplay;
}


void MyScale::run() {
    
    int sign = 0;

    while(modbusConnected == true)
    {
        if(writeToLoadcell != true)
        {
            modbus_read_registers(ctx, readFromRegister, 5, data);
            statusRegisterBinaryReturnValue = statusRegisterBinary(data);

            if(weightGROSSorNET[0] == grossDisplay)
            {
                sign=pow((-1),(statusRegisterBinaryReturnValue[7]));
                emit receivedWeight(sign*data[2]);
                //qDebug() << " WeightGross: " <<  sign*data[2];
            }
            else if(weightGROSSorNET[0] == netDisplay)
            {
                sign=pow((-1),(statusRegisterBinaryReturnValue[8]));
                emit receivedWeight(sign*data[4]);
                //qDebug() << " WeightNetto: " << sign*data[4];
            }
        }
        else
        {
            if(mbCommand[0] != 0)
            {
                modbus_write_registers(ctx, writeToRegister, 1, mbCommand);
                //qDebug() << "mbCommand: " << mbCommand[0];

                if(mbCommand[0] == grossDisplay)
                {
                    weightGROSSorNET[0] = grossDisplay;
                }
		
                else if(mbCommand[0] == netDisplay)
                {
                    weightGROSSorNET[0] = netDisplay;
                }

                mbCommand[0] = 0;
            }
        }
    }
}
