# [Architecture parallèles] Correction Annale 2012-2013
## 1 Nombres complexes (8 points)
### 1.1 (2 points)

```cpp
void complexe_sub_sse2(const double a[2], const double b[2], const double res[2]){
  const __mm128d pk_a = _mm_load_pd(a);
  const __mm128d pk_b = _mm_load_pd(b);
  pk_a = _mm_sub_pd(pk_a, pk_b);
  _mm_store_pd(res, pk_a);
}
```

### 1.2 (3 points)

Ligne | pk_tmp1                                   | pk_tmp2               | pk_tmp3
:---: | :---------------------------------------: | :-------------------: | :---------------------------------------:
10    | a[0] \ a[0]                               | *                     | *
11    | a[0] \ a[0]                               | b[0] \ b[1]           | *
12    | a[0] \ a[0]                               | b[0] \ b[1]           | a[0]xb[0] \ a[0]xb[1]
13    | a[1] \ a[1]                               | b[0] \ b[1]           | a[0]xb[0] \ a[1]xb[1]
14    | a[1] \ a[1]                               | b[1] \ b[0]           | a[0]xb[0] \ a[1]xb[1]
15    | a[1] \ a[1]                               | a[1]xb[1] \ a[1]xb[0] | a[0]xb[0] \ a[1]xb[1]
16    | a[1]xb[1]+a[0]xb[0] \ a[1]xb[0]+a[1]xb[1] | a[1]xb[1] \ a[1]xb[0] | a[0]xb[0] \ a[1]xb[1]
17    | a[1]xb[1]+a[0]xb[0] \ a[1]xb[0]+a[1]xb[1] | a[1]xb[1] \ a[1]xb[0] | a[0]xb[0]-a[1]xb[1] \ a[1]xb[1]-a[1]xb[0]
18    | a[0]xb[0]-a[1]xb[1] \ a[1]xb[0]+a[1]xb[1] | a[1]xb[1] \ a[1]xb[0] | a[0]xb[0]-a[1]xb[1] \ a[1]xb[1]-a[1]xb[0]

### 1.3 (3 points)
**La flemme**

## 2 Tableaux (12 points)
### 2.1 (3 points)
