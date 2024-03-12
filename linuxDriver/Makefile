obj-m += main.o

all:
        make -C /lib/modules/6.1.0-rpi7-rpi-v7/build M=$(PWD) modules

clean:
        make -C /lib/modules/6.1.0-rpi7-rpi-v7/build M=$(PWD) clean