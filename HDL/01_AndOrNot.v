module gates(input a, b, output [2:0]y);
assign y[2]= a & b; // AND gate
assign y[1]= a | b; // OR gate
assign y[0]= ~a; // NOT gate
endmodule

module gates_tb;
wire [2:0]y;
reg a, b;
gates dut(a,b,y);
initial
begin
$dumpfile("shaan-test.vcd");
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