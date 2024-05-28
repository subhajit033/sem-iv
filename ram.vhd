library ieee;

use ieee.std_logic_1164.all;

use ieee.std_logic_arith.all;

use ieee.std_logic_unsigned.all;

entity memory1 is

port(clk: in std_logic ;

cs : in std_logic ;

r : in std_logic ;

w : in std_logic ;

clr: in std_logic;

abus:in std_logic_vector(6 downto 0);

dbus:inout std_logic_vector(7 downto
0));

end memory1;

architecture arch1 of memory1 is

type ma is array(0 to 127) of
std_logic_vector(7 downto 0);

signal mem : ma;

begin

process(clk)

begin

if(rising_edge(clk) and cs='1') then

if w='1' then

mem(conv_integer(unsigned(abus)))<=dbus;

end if;

if r='1' then

dbus<=mem(conv_integer(unsigned(abus)));

end if;

if clr='1' then

for i in 0 to 127 loop

mem(i)<="UUUUUUUU";

end loop;

end if;

end if;

end process;

end arch1;