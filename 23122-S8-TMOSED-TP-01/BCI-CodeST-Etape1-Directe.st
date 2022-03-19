(* ------------------------------------------- *)
(* TMOSED - Manip 1 (BCI) - MO Etape 2 Directe *)
(* TP Grp1 Armand AUDIC & Antoine RONK         *)
(* ------------------------------------------- *)

IF (init) THEN
(* on fait un if pour pouvoir initialiser a n importe quel moment *)
(* On initialise les etats presents et suivants cahcun a l etat 1  *)
    EP := 1 ;
    ES := 1 ;
ELSE
(* bloc G *)
(* en fonction de l etat present EP on fait le calcul de l etat suivant *)
    CASE EP OF
      1:
        IF (operateur) 		(* Q1.operateur => E2*)
        THEN ES := 2;
        END_IF;

      2:
        IF (C6) 			    (* Q2.C6 => E3*)
        THEN ES := 3;
        ELSIF (C1) 			  (* Q2.C1 => E4*)
          THEN ES := 4;
        END_IF;

      3:
        IF (not C6) 		  (* Q3.!C6 => E5 *)
        THEN ES := 5;
        ELSIF(C1) 		  	(* Q3.C1 => E6 *)
            THEN ES := 6;
        END_IF;
      4:
        IF (C6) 		    	(* Q4.C6 => E6 *)
        THEN ES := 6;
        ELSIF (C4) 			  (* Q4.C4 => E7 *)
          THEN ES := 7;
        END_IF;
      5:
        IF (C1) 			    (* Q5.C1 => E8 *)
        THEN ES := 8;
        END_IF;
      6:
        IF (not C6) 		  (* Q6.!C6 => E8 *)
        THEN ES := 8;
        ELSIF (C4) 			  (* Q6.C4 => E9 *)
          THEN ES := 9;
        END_IF;
      7:
        IF (C6) 			    (* Q7.C6 => E9 *)
        THEN ES := 9;
        END_IF;
      8:
        IF (C4) 			    (* Q8.C4 => E10 *)
        THEN ES := 10;
        END_IF;
      9:
        IF (not C6) 		  (* Q9.!C6 => E10 *)
        THEN ES := 10;
        END_IF;
      10: 					      (* Q10 => E1 *)
        ES := 1
    END_CASE;
end_if;

(* bloc M *)
EP := ES; (*l etat present prend la valeur de l etat suivant *)

(* bloc G *)
(* les actionneurs ne s activent que dans les etat qui leurs correspondent *)
A4 := (EP=2) or (EP=3) or (EP=5);
A5 := (EP=2) or (EP=4) or (EP=7);
A3 := (EP=3) or (EP=6) or (EP=9);
A1 := (EP=7) or (EP=9) or (EP=10);
