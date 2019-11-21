/*  
    Write HDL implementation for a 3-bit up-counter using 
    behavioral model. Simulate the same using structural model 
    and depict the timing diagram for valid inputs.
*/
module counter_behav ( count,rst,clk);
input rst, clk;
output reg [2:0] count;
always @(posedge (clk))
if (rst)
    count<= 3'b000;
else
    count<= count + 1;
endmodule


module testmod;
reg r,c;
wire  [2:0] ct;
counter_behav countbeh (ct,r,c);
initial
begin
$dumpfile("shaan.vcd");
$dumpvars(0, testmod);   
    r=1;
    c=0;#100 
    r=0;#200
    $finish;
end
//initial and always run in parallel and starts its execution at 0ns
always #5 c=~c;
endmodule