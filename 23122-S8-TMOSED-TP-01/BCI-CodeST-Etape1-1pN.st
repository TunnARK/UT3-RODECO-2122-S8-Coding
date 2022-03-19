(* --------------------------------------------- *)
(* TMOSED - Manip 1 (BCI) - MO Etape 1 1 parmi N *)
(* TP Grp1 Armand AUDIC & Antoine RONK           *)
(* --------------------------------------------- *)

(* bloc M *)
(* Initialisation des etats suivants lors de l activation d init *)
IF (init) THEN
    es1 := 1;
    es2 := 0;
    es3 := 0;
    es4 := 0;
    es5 := 0;
    es6 := 0;
    es7 := 0;
    es8 := 0;
    es9 := 0;
ELSE (* bloc F *)
(*Equations: etats suivants E en fonction des etats presents Q et des capteurs*)
    (* E1 = Q1.!operateur + Q9.!C1 +  Q8.!C6*)
    es1 := (EP8 and not(C6)) or (EP9 and not(C1)) or (EP1 and not(operateur));
    (* E2 = Q2.!(C1+C6) + Q1.operateur *)
    es2 := (EP2 and not(C1 or C6)) or (EP1 and operateur);
    (* E3 = Q3.!(!C1+C6) + Q2.C1 *)
    es3 := (EP3 and not(not(C1) or C6)) or (EP2 and C1);
    (* E4 = Q4.!(C1+!C6) + Q2.C6 *)
    es4 := (EP4 and not(C1 or not(C6)) or (EP2 and C6));
    (* E5 = Q5.!C6 + Q3.!C1 *)
    es5 := (EP3 and not(C1)) or (EP5 and not(C6));
    (* E6 = Q6.!(!C1+!C6) + Q3.C6 + Q4.C1 *)
    es6 := (EP6 and not(not(C1) or not(C6))) or (EP3 and C6) or (EP4 and C1);\
    (* E7 = Q7.!C1 + Q4.!C6 *)
    es7 := (EP7 and not(C1)) or (EP4 and not(C6));
    (* E8 = Q8.!(!C6) + Q5.C6 + Q6.!C1 *)
    es8 := (EP8 and not(not(C6))) or (EP5 and C6) or EP6 and not(C1);
    (* E9 = Q9.!(!C1) + Q7.C1 + Q6.!C6 *)
    es9 := (EP9 and not(not(C1))) or (EP7 and C1) or EP6 and not(C6);
END_IF;

(* bloc M *)
(* Les etats presents prennent la valeurs de leurs etats suivants *)
EP1 := es1;
EP2 := es2;
EP3 := es3;
EP4 := es4;
EP5 := es5;
EP6 := es6;
EP7 := es7;
EP8 := es8;
EP9 := es9;

(* bloc G *)
(* Actionneurs actives uniquement lorsqu un des ces etats presents est a 1 *)
A4 := (EP2) OR (EP3) OR (EP4) OR (EP6) OR (EP7) OR (EP9);
A5 := (EP2) OR (EP3) OR (EP4) OR (EP5) OR (EP6) OR (EP8);
