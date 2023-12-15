// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences  
// Creator: Dr.  Tony Drummond
// Date Created: 9/01/2022
// Last revisited: 9/20/2023
//
//  C++ Timing functions that use the C++ high resolution timing chron API and data
//  structures.  It is available on C++ 11 and later versions

//  mytiming.h in ../../Include/mytiming.h contains the header file with the API 
//                and other dependencies

#include "mytimings.h"

// WTimeChrono: Returns a high-resolution snapshot of the system's wall-clock time 
//   INPUTS: No inputs required, it directly access the system's wall-clock time
//   OUTPUT: returns a structure of type chrono::high_resolution_clock::time_point
//           with the current wall-clock time

high_resolution_clock::time_point WTimeChrono(){
  return high_resolution_clock::now();
}

// WTElapse: Elapse wall-clock time between start and endt 
//          (i.e. Elapsed = startt - endt)
//   INPUTS: startt : start wall-clock timestamp
//             endt : end wall-clock timestamp
//   OUTPUT: Elapse time in nanoseconds
long double WTElapsed(high_resolution_clock::time_point startt, 
                 high_resolution_clock::time_point endt){
    duration<double> elapsed;
    long double      nelapsed;
      
    elapsed  = duration_cast<duration<double> > (endt - startt);
    nelapsed = duration_cast<nanoseconds>(elapsed).count();
  
    return nelapsed;
}

// WTElapseMicro: Elapse wall-clock time between start and endt in microseconds 
//                (i.e. Elapsed = startt - endt). Similar to WTElapse but µseconds
//   INPUTS: startt : start wall-clock timestamp
//             endt : end wall-clock timestamp
//   OUTPUT: Elapse time in microseconds

long double WTElapsedMicro(high_resolution_clock::time_point startt, 
                 high_resolution_clock::time_point endt){
    duration<double> elapsed;
    long double      melapsed;
    elapsed  = duration_cast<duration<double> > (endt - startt); 
    melapsed = duration_cast<microseconds>(elapsed).count();
  
    return melapsed;
}
