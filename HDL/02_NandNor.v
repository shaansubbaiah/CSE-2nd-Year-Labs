/*
    Write HDL implementation for the following Logic
        a. NAND/NOR
    Simulate the same using structural model and depict 
    the timing diagram for valid inputs.
*/
module gates(input a, b, output [1:0]y);
assign y[1]= a ~| b; // NOR gate
assign y[0]= a ~& b; // NAND gate
endmodule

module gates_tb;
wire [1:0]y;
reg a, b;
gates dut(a,b,y);
initial
begin
$dumpfile("shaan.vcd");
$dumpvars(0, gates_tb);
a = 1'b0;
b = 1'b0;
#50;
a = 1'b0;
b = 1'b1;
#50;
a = 1'b1;
b = 1'b0;
#50;
a = 1'b1;
b = 1'b1;
#50;
end
endmodule