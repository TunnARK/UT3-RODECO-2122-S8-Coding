
#ifndef BRAS_H
#define BRAS_H
#include "systeme.h"

#include <string>
#include vector



/**
  * class Bras
  * 
  */

class Bras : public systeme
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Bras ();

  /**
   * Empty Destructor
   */
  virtual ~Bras ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * @param  x
   */
  void StopTi (short x)
  {
  }


  /**
   * @param  x
   */
  void StartTi (short x)
  {
  }


  /**
   * @param  x
   */
  void Stop2 (short x)
  {
  }


  /**
   * @param  x
   */
  void Start2 (short x)
  {
  }


  /**
   * @param  x
   */
  void Stop1 (short x)
  {
  }


  /**
   * @param  x
   */
  void Start1 (short x)
  {
  }

protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  bool SCD;
  bool FinPrise;
  bool FinPose;
  bool SCG;
  bool T1;
  bool PE;
  bool T2;
  bool Ti;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of SCD
   * @param new_var the new value of SCD
   */
  void setSCD (bool new_var)   {
      SCD = new_var;
  }

  /**
   * Get the value of SCD
   * @return the value of SCD
   */
  bool getSCD ()   {
    return SCD;
  }

  /**
   * Set the value of FinPrise
   * @param new_var the new value of FinPrise
   */
  void setFinPrise (bool new_var)   {
      FinPrise = new_var;
  }

  /**
   * Get the value of FinPrise
   * @return the value of FinPrise
   */
  bool getFinPrise ()   {
    return FinPrise;
  }

  /**
   * Set the value of FinPose
   * @param new_var the new value of FinPose
   */
  void setFinPose (bool new_var)   {
      FinPose = new_var;
  }

  /**
   * Get the value of FinPose
   * @return the value of FinPose
   */
  bool getFinPose ()   {
    return FinPose;
  }

  /**
   * Set the value of SCG
   * @param new_var the new value of SCG
   */
  void setSCG (bool new_var)   {
      SCG = new_var;
  }

  /**
   * Get the value of SCG
   * @return the value of SCG
   */
  bool getSCG ()   {
    return SCG;
  }

  /**
   * Set the value of T1
   * @param new_var the new value of T1
   */
  void setT1 (bool new_var)   {
      T1 = new_var;
  }

  /**
   * Get the value of T1
   * @return the value of T1
   */
  bool getT1 ()   {
    return T1;
  }

  /**
   * Set the value of PE
   * @param new_var the new value of PE
   */
  void setPE (bool new_var)   {
      PE = new_var;
  }

  /**
   * Get the value of PE
   * @return the value of PE
   */
  bool getPE ()   {
    return PE;
  }

  /**
   * Set the value of T2
   * @param new_var the new value of T2
   */
  void setT2 (bool new_var)   {
      T2 = new_var;
  }

  /**
   * Get the value of T2
   * @return the value of T2
   */
  bool getT2 ()   {
    return T2;
  }

  /**
   * Set the value of Ti
   * @param new_var the new value of Ti
   */
  void setTi (bool new_var)   {
      Ti = new_var;
  }

  /**
   * Get the value of Ti
   * @return the value of Ti
   */
  bool getTi ()   {
    return Ti;
  }
private:


  void initAttributes () ;

};

#endif // BRAS_H
