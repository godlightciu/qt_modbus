
modbus_t  *ctx; //创建一个modbus_t类型的上下文，用来打开串口
uint16_t tab_reg[4]; //存储传感器数值

ctx = modbus_new_rtu("/dev/ttyS6",9600,'N',8,1); //打开串口
modbus_rtu_set_serial_mode(ctx, MODBUS_RTU_RS485);
modbus_connect(ctx)；//建立和传感器的连接
mstruct timeval t;
t.tv_sec = 0;
t.tv_usec = 1000000;//设置超时时间1000ms
modbus_set_response_timeout(ctx,&t);

modbus_set_slave(ctx,1);//温湿度传感器的modbus站地址为0x01；

int regs=modbus_read_registers(ctx,0x0100,4,tab_reg); // 寄存器地址为0100，要读的寄存器个数为2。若读取成功，温度数值置于tab_regp[0]，湿度数值置于tab_reg[1]，分别除以10，就得到正确的温湿度数值。

QMessageBox::about(NULL, "报告", QString("Rtu 读取寄存器的个数:%1").arg(regs));
QString qs=QString("%1\n%2\n%3\n%4\n").arg(tab_reg[0]).arg(tab_reg[1]).arg(tab_reg[2]).arg(tab_reg[3]);
QMessageBox::information(this,"Info",qs);
modbus_close(ctx);
modbus_free(ctx); //释放并关闭modbus
