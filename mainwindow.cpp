#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QMessageBox>
#include "modbus/modbus.h"
#include "modbus/modbus-rtu.h"
#include "modbus/modbus-version.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()// 打开电磁阀v4
{
    modbus_t * ctx;// set modbus object
    uint8_t raw_req[]={0x04, 0x05, 0x00, 0x01, 0xFF, 0x00, 0xDD, 0xAF};
    int req_length;
    uint8_t rsp [MODBUS_RTU_MAX_ADU_LENGTH];

    ctx = modbus_new_rtu("/dev/ttyS6", 9600, 'N', 8, 1); //创建Modbus RTU上下文;相同的端口只能同时打开一个;
    modbus_rtu_set_serial_mode(ctx, MODBUS_RTU_RS485);
    modbus_set_slave(ctx, 0); //设置modbus-rtu模式;设置 modbus 从机地址 0

    modbus_connect(ctx);
    /*
    if (sign == -1) {
        QString qs = QString("Connection failed: %s\n");
        QMessageBox::information(this,"Info",qs);
        modbus_free(ctx);
    }
    */

    req_length = modbus_send_raw_request(ctx, raw_req,  6*sizeof(uint8_t) );
    modbus_receive_confirmation(ctx, rsp);
    //add receive_check
    modbus_receive_confirmation(ctx, rsp);

    QMessageBox::about(NULL,"Info",QString("Open V4 sucessfully"));

    modbus_close(ctx);
    modbus_free(ctx);
}

void MainWindow::on_pushButton_3_clicked()//关闭电磁阀v4
{
    modbus_t * ctx;// set modbus object
    uint8_t raw_req[]={0x04, 0x05, 0x00, 0x01, 0x00, 0x00, 0x9C, 0x5F};
    int req_length;
    uint8_t rsp [MODBUS_RTU_MAX_ADU_LENGTH];

    ctx = modbus_new_rtu("/dev/ttyS6", 9600, 'N', 8, 1); //创建Modbus RTU上下文;相同的端口只能同时打开一个;
    modbus_rtu_set_serial_mode(ctx, MODBUS_RTU_RS485);
    modbus_set_slave(ctx, 0); //设置modbus-rtu模式;设置 modbus 从机地址 0

    modbus_connect(ctx);
    /*
    if (sign == -1) {
        QString qs = QString("Connection failed: %s\n");
        QMessageBox::information(this,"Info",qs);
        modbus_free(ctx);
    }
    */

    req_length = modbus_send_raw_request(ctx, raw_req,  6*sizeof(uint8_t) );
    modbus_receive_confirmation(ctx, rsp);

    QMessageBox::about(NULL,"Info",QString("Close V4 successfully"));

    modbus_close(ctx);
    modbus_free(ctx);

}

void MainWindow::on_pushButton_2_clicked()//打开电磁阀v11
{
    modbus_t * ctx;// set modbus object
    uint8_t raw_req[]={0x0B, 0x05, 0x00, 0x01, 0xFF, 0x00, 0xDD, 0x50};
    int req_length;
    uint8_t rsp [MODBUS_RTU_MAX_ADU_LENGTH];

    ctx = modbus_new_rtu("/dev/ttyS6", 9600, 'N', 8, 1); //创建Modbus RTU上下文;相同的端口只能同时打开一个;
    modbus_rtu_set_serial_mode(ctx, MODBUS_RTU_RS485);
    modbus_set_slave(ctx, 0); //设置modbus-rtu模式;设置 modbus 从机地址 0

    modbus_connect(ctx);
    /*
    if (sign == -1) {
        QString qs = QString("Connection failed: %s\n");
        QMessageBox::information(this,"Info",qs);
        modbus_free(ctx);
    }
    */

    req_length = modbus_send_raw_request(ctx, raw_req,  6*sizeof(uint8_t) );
    modbus_receive_confirmation(ctx, rsp);

    QMessageBox::about(NULL,"Info",QString("Open V11 successfully"));

    modbus_close(ctx);
    modbus_free(ctx);

}

void MainWindow::on_pushButton_4_clicked()//关闭电磁阀v11
{
    modbus_t * ctx;// set modbus object
    uint8_t raw_req[]={0x0B, 0x05, 0x00, 0x01, 0x00, 0x00, 0x9C, 0xA0};
    int req_length;
    uint8_t rsp [MODBUS_RTU_MAX_ADU_LENGTH];

    ctx = modbus_new_rtu("/dev/ttyS6", 9600, 'N', 8, 1); //创建Modbus RTU上下文;相同的端口只能同时打开一个;
    modbus_rtu_set_serial_mode(ctx, MODBUS_RTU_RS485);
    modbus_set_slave(ctx, 0); //设置modbus-rtu模式;设置 modbus 从机地址 0

    modbus_connect(ctx);
    /*
    if (sign == -1) {
        QString qs = QString("Connection failed: %s\n");
        QMessageBox::information(this,"Info",qs);
        modbus_free(ctx);
    }
    */

    req_length = modbus_send_raw_request(ctx, raw_req,  6*sizeof(uint8_t) );
    modbus_receive_confirmation(ctx, rsp);

    QMessageBox::about(NULL,"Info",QString("Close V11 successfully"));

    modbus_close(ctx);
    modbus_free(ctx);

}
