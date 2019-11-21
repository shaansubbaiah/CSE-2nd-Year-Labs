/*
    Write HDL implementation for a 3-bit full adder using 
    data flow model. Simulate the same using structural model 
    and depict the timing diagram for valid inputs.
*/
module fa(a,b,cin,s,cout);
input a,b,cin;
output s,cout;
assign s =a^b^cin;
assign cout = (a&b) | (b&cin) | (cin&a);
endmodule


module fa_test;
reg a,b,cin;
wire s, cout;
fa f1(a,b,cin,s,cout);
initial 
    begin
    $dumpfile("shaan.vcd");
    $dumpvars(0, fa_test); 
        a=1; b=1; cin=0; #5
        a=1; b=1; cin=1; #5
        a=0; b=1; cin=0; #100 
        $finish;
    end
endmodule   