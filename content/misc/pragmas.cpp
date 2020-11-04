#pragma GCC optimize ("O3", "unroll-loops")
// #pragma GCC optimize ("fast-math")
#pragma GCC target("avx,avx2,fma,mmx,abm,bmi,bmi2")
// tip: `lscpu` on the contest machine

// for math:
//  - writing your own complex, etc. can increase speed
//  - use Ofast on floating points with caution!
// stuff to put before a loop:
//  - unroll count (0 or 1 -> no unroll)
#pragma GCC unroll 10
//  - for a loop that you're sure can be vectorized
#pragma GCC ivdep

// to see what are optimized, call gcc with
//  -fopt-info -fopt-info-loop -fopt-info-loop-missed
//  -fopt-info-vec -fopt-info-vec-missed
