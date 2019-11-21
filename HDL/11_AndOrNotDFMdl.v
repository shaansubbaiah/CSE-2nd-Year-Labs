/*
    Write HDL implementation for AND/OR/NOT gates using 
    data flow model. Simulate the same using structural 
    model and depict the timing diagram for valid inputs.
*/
module gates(input a, b, output [2:0]y);
assign y[2]= a & b; // AND gate
assign y[1]= a | b; // OR gate
assign y[0]= ~a; // NOT gate
endmodule	


module modulegates_tb;
wire [2:0]y;
reg a, b;
gates dut(.y(y), .a(a), .b(b));
initial
begin
$dumpfile("shaan.vcd");
$dumpvars(0, modulegates_tb);  
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