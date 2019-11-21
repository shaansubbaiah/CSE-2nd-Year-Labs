/*  
    Write HDL implementation for a SR flip-flop using behavioral 
    model. Simulate the same using structural model and depict 
    the timing diagram for valid inputs.
*/
module SR_FF (sr, clk, q, qb);
input [1:0] sr;
input clk;
output reg q=1'b0;
output reg qb;
always @ (posedge clk)
begin
    case (sr)
        2'b00 : q = q;
		2'b01 : q = 1'b0;
		2'b10 : q = 1'b1;
		2'b11 : q = 1'bz;
    endcase
qb =~ q;
end
endmodule

module testsrflipf;
reg [1:0] A;
reg c;
wire x, xb;
SR_FF srff(A,c,x,xb);
initial c=1'b0;
always #5 c=~c;
initial 
begin 
$dumpfile("shaan.vcd");
$dumpvars(0, testsrflipf);
    A=2'b00; #10
    A=2'b01;#10
    A=2'b10;#10
    A=2'b11;
    #20 $finish;
end
endmodule