/*
    Write HDL implementation for a 4:1 Multiplexer. Simulate the 
    same using structural model and depict the timing diagram for 
    valid inputs.
*/    
module Multiplexer4to1(Do, Din, En);
input En;
input [3:0] Din;
output Do;
reg Do;
always @ (En or Din)
begin
if (En)
    begin
        case (Din)
            4'b0001: Do = 2'b00;
            4'b0010: Do = 2'b01;
            4'b0100: Do = 2'b10;
            4'b1000: Do = 2'b11;
            default: Do = 2'bzz;
        endcase
    end
end
endmodule


module multiplexer_tb;
reg [3:0] Din;
reg En;
wire Do;
Multiplexer4to1 mux(
    .Do(Do), 
    .Din(Din), 
    .En(En)
);
initial 
begin
$dumpfile("shaan.vcd");
$dumpvars(0, multiplexer_tb);
    // Initialize Inputs
    En = 1; 
    Din = 4'b0001; #100;
    Din = 4'b0010; #100;
    Din = 4'b0100; #100;
    Din = 4'b1000; #100;
end
endmodule