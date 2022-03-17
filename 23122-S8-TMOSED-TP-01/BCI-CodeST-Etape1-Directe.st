(* ------------------------------------------- *)
(* TMOSED - Manip 1 (BCI) - MO Etape 1 Directe *)
(* TP Grp1 Armand AUDIC & Antoine RONK         *)
(* ------------------------------------------- *)
IF (init) then
    EP := 1 ;
    ES := 1 ;
ELSE (* bloc G *)
    CASE EP OF
      1:
        IF (operateur)
        THEN ES := 2;
        END_IF;

      2:
        IF (C6)
        THEN ES := 3;
        ELSIF (C1)
          THEN ES := 4;
        END_IF;

      3:
        IF (not C6)
        THEN ES := 5;
        ELSIF(C1)
            THEN ES := 6;
        END_IF;
      4:
        IF (C6)
        THEN ES := 6;
        ELSIF (C4)
          THEN ES := 7;
        END_IF;
      5:
        IF (C1)
        THEN ES := 8;
        END_IF;
      6:
        IF (not C6)
        THEN ES := 8;
        ELSIF (C4)
          THEN ES := 9;
        END_IF;
      7:
        IF (C6)
        THEN ES := 9;
        END_IF;
      8:
        IF (C4)
        THEN ES := 10;
        END_IF;
      9:
        IF (not C6)
        THEN ES := 10;
        END_IF;
      10:
        ES := 1
    END_CASE;
end_if;

(* bloc M *)
EP := ES;

(* bloc G *)
A4 := (EP=2) or (EP=3) or (EP=5);
A5 := (EP=2) or (EP=4) or (EP=7);
A3 := (EP=3) or (EP=6) or (EP=9);
A1 := (EP=7) or (EP=9) or (EP=10);
