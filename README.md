# max-of-exponantials
Estimating Hₙ = 1 + ½ + … + 1/n in C++ using only random numbers


## The idea
If X₁, …, Xₙ are i.i.d. Exp(1), then E(max((X1,..,Xn))) = Hₙ 


## Results (n = 100)
| N    | estimate | error   |
|------|----------|---------|
| 10⁶  | 5.18783  | 0.0005  |

Coverage of 95% intervals over 2,000 runs: 95.7%.


## Mathematical proof 
[Adobe Scan 07-Nov-2026_14-16-42.pdf](https://github.com/user-attachments/files/34522955/Adobe.Scan.07-Nov-2026_14-16-42.pdf)

