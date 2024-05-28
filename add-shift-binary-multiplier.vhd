library IEEE;

use IEEE.STD_LOGIC_1164.ALL;

use IEEE.STD_LOGIC_arith.ALL;

use IEEE.STD_LOGIC_unsigned.ALL;

entity binary_multiplier is

Port ( m : in STD_LOGIC_VECTOR (3 downto 0);

q : in STD_LOGIC_VECTOR (3 downto 0);

r : out STD_LOGIC_VECTOR (7 downto 0));

end entity;

architecture multiplier of binary_multiplier is

begin

process(m,q)

variable acc: std_logic_vector(8 downto 0);

variable multiplicand:std_logic_vector(4 downto 0);

begin

acc(8 downto 4):="00000";

acc(3 downto 0):=q;

multiplicand:='0' & m;

for i in 1 to 4 loop

if acc(0)='1' then

acc(8 downto 4):=acc(8 downto 4)+ multiplicand;

end if;

acc:='0' & acc(8 downto 1);

end loop;

r<= acc(7 downto 0);

end process;

end multiplier;