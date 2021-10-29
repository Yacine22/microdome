/* This a serial i2c protocol from Raspberry Pi  */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>

void openI2CBus(int& file){
    if((file = open("/dev/i2c-1", O_RDWR)) < 0){
        perror("Failed to open the bus\n");
        return;
    }
}

void connecttoSlave(int& file, unsigned char slaveAddr){
    if (ioctl(file, I2C_sLAVE, slaveAddr) < 0){
        perror("Failed to connect to the Arduino\n"); 
        return; 
    }
}

void sendLong(int& file, long value){
    unsigned char bytes[sizeof(long)];

    for (int j = 0; j < sizeof(long); ++j)
        bytes[j] = value >> j * 8;
    
    if (write(file, bytes, sizeof(long)) != sizeof(long)) {
        perror("Failed to send data\n"); 
        return; 
    }
}

void receiveLong(int& file, long& value){
    unsigned char bytes[sizeof(long)];

    if (read(file, bytes, sizeof(long)) != sizeof(long)){
        perror("Failed to receive data\n");
        return; 
    }

    value = 0; 

    for (int j = 0; j < sizeof(long); ++j)
    value += bytes[j] << j * 8; 
    
}


int main(){
    int fd; 
    openI2CBus(fd); 
    connecttoSlave(fd, 0x44); 

    long dataSent(0); //{0}
    long dataReceived;

    for (int k = 0; k < 10000; ++k) {
        sendLong(fd, ++dataSent); 
        printf("value Sent: %d\n", dataSent); 
        receiveLong(fd, dataReceived); 
    }

    close(fd); 
    return 0; 

}