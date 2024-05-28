library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity alu4bit is
port(a,b : in std_logic_vector(3 downto 0);
s: in std_logic_vector(1 downto 0);
cin: in std_logic;
r: out std_logic_vector(3 downto 0);
cout : out std_logic );
end alu4bit;
architecture arch1 of alu4bit is
begin
process(a,b,s,cin)
variable sw: std_logic_vector(2 downto 0);
variable a1,b1,r1: std_logic_vector(4 downto 0);
begin

sw(0):=cin;
sw(1):=s(0);
sw(2):=s(1);
a1:='0' & a;
b1:='0' & b;case sw is
when "000" => r1:=a1+b1;
when "001" => r1:=a1+b1+'1';
when "010" => r1:=a1+not(b1);
when "011" => r1:=a1+not(b1)+'1';
when "100" => r1:=a1-'1';
when "101" => r1:=a1;
when "110" => r1:=a1;
when "111" => r1:=a1+'1';
when others=> r1:="UUUUU";
end case;
r<=r1(3 downto 0); cout<=r1(4);
end process;
end arch1;