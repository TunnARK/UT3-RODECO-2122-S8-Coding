// slide p43

package Buf;
import java.util.concurrent.locks.*;

public class PC_Buf {
  private int N ; private Object Contenu[];
  int Tete=0, Queue=0, Taille=0 ;

  private final Lock verrou = new ReentrantLock();
  private final Condition Non_Plein = verrou.newCondition();
  private final Condition Non_Vide = verrou.newCondition();

  public PC_Buf (int argSize) {
    N = argSize; /* creation d'un tampon de taille argsize*/
    Contenu = new Object[N];
  }
}

// silde p44

public void Deposer (Object info) throws InterruptedException {
  verrou.lock();
  if (Taille == N)
    try{
      System.out.println("Buffer PLEIN thread" +Thread.currentThread().getName()); Non_Plein.await() ;
    }
    catch (InterruptedException e) {
      e.printStackTrace();
    }
    System.out.println ("ECRITURE thread " +Thread.currentThread().getName());
    Contenu [Queue] = info ;
    Taille++ ;
    if (Queue == N-1) Queue = 0 ;
    else Queue++ ;
    System.out.println ("signal Non_Vide thread " +Thread.currentThread().getName());
    Non_Vide.signal ();
    verrou.unlock();
}

// slide 45

public Object Retirer () throws InterruptedException {
  Object info; verrou.lock();
  if (Taille == 0)
    try{
      System.out.println("Buffer VIDE thread" +Thread.currentThread().getName());
      Non_Vide.await () ;
    }
    catch (InterruptedException e) {
      e.printStackTrace();
    }

    System.out.println("LECTURE thread" +Thread.currentThread().getName());
    info = Contenu [Tete] ;
    Taille--;
    if (Tete == N-1) Tete = 0 ;
    else Tete++ ;
    Non_Plein.signal ();
    verrou.unlock();
    return (info) ;
  }
}

// slide 46

import Buf.PC_Buf;
public class Producteur extends Thread {
  private String threadName = null;
  PC_Buf Monbuffer ;
  public Producteur (String Name, PC_Buf Buffer) {
    this.threadName = Name; MonBuffer = Buffer;
  }
  int cpt = 0;
  Object data;
  public void run() {
    long start = System.currentTimeMillis(); // boucle tant que la durée de vie du Thread est < à 5 secondes
    while( System.currentTimeMillis() < ( start + (1000 * 5))) {
      System.out.println("Demande Accès Producteur au Buffer " +this.threadName);
      data= cpt+1;
      try {
        MonBuffer.Deposer (data);
        // pause
        cpt+=1; Thread.sleep(500);
      }
      catch (InterruptedException ex) {}
    }
  }
}

// slide 47

import Buf.PC_Buf;
public class Consumer extends Thread{
  private String threadName = null;
  PC_Buf MonBuffer = new PC_Buf(10);
  public Consumer(String Name, PC_Buf Buffer) {
    this.threadName = Name; MyTampon = Tampon;
  }
  int cpt = 0; Object data;
  public void run() {
    long start = System.currentTimeMillis(); // boucle tant que la durée de vie du Thread est < à 5 secondes
    while( System.currentTimeMillis() < ( start + (1000 * 5))) {
      System.out.println("Demande Accès Consumer au Buffer " +this.threadName);
      data= cpt+1; try {
        data = MonBuffer.Retirer ();
        // pause
        cpt+=1;
        Thread.sleep(50);
      }
      catch (InterruptedException ex) {}
    }
  }
}

// slide p48

import Buf.*;
public class PC_main {
  public static void main(String[] args) {
    PC_Buf Tampon = new PC_Buf (3);
    for(int i=1; i<5; i++) {
      Producteur Productor = new Producteur("Thread-PROD" + i, Tampon);
      System.out.println("creation Producteur " +i ); Productor.start();
    }

    for(int i=1; i<5; i++) {
      Consumer Cons = new Consumer("Thread-CONS" + i, Tampon);
      System.out.println("creation Consumer " +i );
      Cons.start();
    }

    long start = System.currentTimeMillis();
    while( System.currentTimeMillis() < ( start + (1000 * 10))) {
      System.out.println("Ligne affichée par le main");
      try {
        Thread.sleep(800);
      } catch (InterruptedException ex) {}
    }
  }
}
