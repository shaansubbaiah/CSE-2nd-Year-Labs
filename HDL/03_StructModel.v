/*
    Write HDL implementation for the following Logic
        LMAO CANT INCLUDE PIC HERE
    Simulate the same using structural model and depict the timing 
    diagram for valid inputs.
*/
module addor(A,B,C,D,Y);
input A,B,C,D;
output Y;
wire and_opl, and_op2;
and gl(and_opl,A,B);    // g1 upper AND
and g2(and_op2,C,D); // g2 represents lower AND
or g3(Y,and_opl,and_op2); // g3 represents the OR gate
endmodule

module test_andor;
reg a,b,c,d;
wire y;
addor ao(a,b,c,d,y);
initial 
begin
$dumpfile("shaan.vcd");
$dumpvars(0, test_andor);
a=0; b=1; c=1; d=1; #10
a=0; b=0; c=1; d=0; #10
$finish;
end
endmodule