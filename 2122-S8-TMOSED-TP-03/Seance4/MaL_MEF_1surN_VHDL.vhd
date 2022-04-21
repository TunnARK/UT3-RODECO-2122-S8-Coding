-- MaL_MEF_1surN_VHDL.vhd
-- date   : 21 avril 2022
-- auteur : ACA & RKA

library ieee;
use ieee.std_logic_1164.all;

entity MaL_MEF_1surN_VHDL is
port (clk, init 	: in std_logic ;
 Accept, Cancel, Po : in std_logic ;
 Alarme, Moteur, Sens, Validation : out std_logic) ;
end MaL_MEF_1surN_VHDL ;

architecture archi_RdP of MaL_MEF_1surN_VHDL is
signal EP_0, EP_1, EP_2, ES_0, ES_1, ES_2 : std_logic ;

begin

process (Accept, Cancel, Po, EP_0, EP_1, EP_2)
begin
-- inserer le bloc F
  ES_2 <= (EP_1 and not(Po)) or (EP_2 and not(not(Po))) ;

  ES_0 <= (EP_1 and Accept and not(Po)) or (EP_2 and not(Accept)) or (EP_2 and Cancel and Po) or (EP_0 and not(Accept and not(Po))) or (EP_0 and not(not(Accept))) or (EP_0 and not(Cancel and Po)) ;

  ES_1 <= (EP_0 and not(Po)) or (EP_2 and not(Cancel)) or (EP_1 and not(not(Po))) or (EP_1 and not(not(Cancel))) ;
--
end process ;

process (init, clk, ES_0, ES_1, ES_2)
begin
	if (init='1') then
		EP_0 <= '0' ;
		EP_1 <= '1' ;
		EP_2 <= '0' ;
	else
		if ((clk'event) and (clk='1')) then
			EP_0 <= ES_0 ;
			EP_1 <= ES_1 ;
			EP_2 <= ES_2 ;
		end if ;
	end if ;
end process ;

-- inserer le bloc F
Alarme <= EP_0  or EP_2 ;
Sens <= EP_0  or EP_2 or EP_1 ;
Moteur <= EP_0  or EP_1 ;

-- A conserver pour le type d appui bouton
Validation <= '0' ;

end archi_RdP ;
