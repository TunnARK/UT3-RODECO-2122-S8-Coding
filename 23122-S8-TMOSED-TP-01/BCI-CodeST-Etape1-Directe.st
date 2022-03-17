(* ------------------------------------------- *)
(* TMOSED - Manip 1 (BCI) - MO Etape 1 Directe *)
(* TP Grp1 Armand AUDIC & Antoine RONK         *)
(* ------------------------------------------- *)
test
(* BLOC F *)
CASE etatpresent OF
  1:
    IF (op)
    THEN etatsuivant := 2;
    END_IF;

  2:
    IF (C1)
    THEN etatsuivant := 3;
    ELSIF (C6)
      THEN etatsuivant := 4;
    END_IF;

  3:
    IF ((not C1) and C6)
    THEN etatsuivant := 5;
    END_IF;
  4:
    IF (C1)
    THEN etatsuivant := 6;
    ELSIF (not C6)
      THEN etatsuivant := 7;
    END_IF;
  5:
    IF (C6)
    THEN etatsuivant := 8;
    END_IF;
  6:
    IF (not C1)
    THEN etatsuivant := 8;
    ELSIF (not C6)
      THEN etatsuivant := 9;
    END_IF
  7:
    IF (C1)
    THEN etatsuivant := 9;
    END_IF
  8:
    IF (not C6)
    THEN etatsuivant := 10;
    END_IF
  9:
    IF (not C1)
    THEN etatsuivant := 10;
    END_IF
  ELSE etatsuivant := 1;
END_CASE;

(* bloc M et initialisation de la MEF *)
IF (Inter1)
THEN etatsuivant := 1;
END_IF;

etatpresent := etatsuivant;

(* bloc G *)
S := (etatpresent=2);
