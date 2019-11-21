/*
    Write HDL implementation for a 4-bit right shift register 
    using behavioral model. Simulate the same using structural 
    model and depict the timing diagram for valid inputs.
*/

module Rshiftregister(input clk, input clrb, input SDR, output reg [3:0]Q);
//serial in, parallel out
always @ (posedge(clk), negedge(clrb))

if (~clrb) 
    Q<=4'b0000;
else 
    Q<={SDR, Q[3:1]};
endmodule


module testRshiftregister; 
reg clk,clrb,SDR;
wire [3:0]Q;

Rshiftregister RS(clk, clrb, SDR, Q );
initial
begin  
$dumpfile("shaan.vcd");
$dumpvars(0, testRshiftregister);
clk=1;
clrb=0;  
SDR=1;    
#10 
clrb=1;
SDR=1;
#15
SDR=0;   
#20 
$finish;
end
//initial and always run in parallel and starts its execution at 0ns
always #5 clk=~clk;
endmodule