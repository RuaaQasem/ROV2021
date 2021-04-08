/*
 * I2C_interface.h
 *
 * Created: 4/6/2021 12:59:42 PM
 *  Author: Laptop Market
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
#define WRITE 0 
#define READ  1
#define WRITE_STOP_CONDITION 1
#define READ_STOP_CONDITION  1
#define WRITE_ERROR 0
#define READ_ERROR  0
#define WRITE_DONE 2
void  MI2C_voidAvrIntialization(void);
u8  MI2C_voidAvrState(void);
u8  MI2C_voidAvrSlaveWrite(char Data);
char  MI2C_u8AvrSlaveRead(void);

#endif /* I2C_INTERFACE_H_ */