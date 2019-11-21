/*
    Write HDL implementation for a 2-to-4 decoder. Simulate 
    the same using structural model and depict the timing 
    diagram for valid inputs.
*/
module decoder_case(Do, Din, En);
input En;
input [1:0] Din;
output [3:0]Do;

reg [3:0]Do;

always @ (En or Din)
begin
if (En)
begin
case (Din)
    2'b00: Do = 4'b0001;
    2'b01: Do = 4'b0010;
    2'b10: Do = 4'b0100;
    2'b11: Do = 4'b1000;
    default: Do=4'bzzzz;
endcase
end
end
endmodule


module decoder_tb_v;
reg [1:0] Din;
reg En;
wire [3:0] Do;

decoder_case uut(
    .Do(Do), 
    .Din(Din), 
    .En(En)
);
initial 
begin
$dumpfile("shaan.vcd");
$dumpvars(0, decoder_tb_v);
    // Initialize Inputs
    En = 1; 
    Din = 2'b00; #100;
    Din = 2'b01; #100;
    Din = 2'b10; #100;
    Din = 2'b11; #100;
end
endmodule