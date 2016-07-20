#include "../inc/simulation.h"


Simulation::Simulation(QObject *parent) :
    QThread(parent)
{

    statusRegisterBinaryTempValue = new int[16];
    statusRegisterBinaryReturnValue = new int[16];
}


Simulation::~Simulation()
{
    //
    delete statusRegisterBinaryTempValue;
    delete statusRegisterBinaryReturnValue;
}


int* Simulation::statusRegisterBinary(uint16_t number[]) {

    uint16_t remainder=0, i=0, decimal=number[0];

    do {
        remainder = decimal%2;
        decimal = decimal/2;
        statusRegisterBinaryTempValue[i] = remainder;
        i = i+1;

    } while(decimal>0);

    return statusRegisterBinaryTempValue;
}


void Simulation::run() {

    int sign = 0;


    while(modbusConnected == true)
    {
        // Data annarsstadar fra ...
        // modbus_read_registers(ctx, readFromRegister, 5, data);
        statusRegisterBinaryReturnValue = statusRegisterBinary(data);

        sign=pow((-1),(statusRegisterBinaryReturnValue[7]));
        emit receivedWeight(sign*data[2]);
        //qDebug() << " WeightGross: " <<  sign*data[2];
    }
}
