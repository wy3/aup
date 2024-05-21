<br>

<p align="center">
  <img src="https://github.com/autoplus-lang/aup/blob/dev/aup.png?raw=true" width="120px" />
  <h3 align="center">The AutoIt+ programming language</h3>
  <p align="center">Language design: <a href="https://aup.nomi.dev<">aup.nomi.dev</a></p>
</p>

<br>

### 🚧 Why archived?

This repository has been archived. While the goal of creating a new language implementation for AutoIt (plus some new syntaxes) was ambitious, the challenges of building a custom runtime proved to be significant.
Due to my current workload commitments, further development on this project is infeasible. The provided code serves as a reference for those interested in exploring alternative approaches to AutoIt language extensions.

### ✨ A new future?

> AutoSharp

While the this compiler was written in C and aimed for a full rewrite, a significant milestone has been achieved with a successful transpiler translating AutoIt(+) code into C#.
This transpiler resides in a separate repository and isn't included here. This success story lays the groundwork for the potential development of a full-fledged compiler that harnesses the power of the .NET platform.
Imagine seamless integration with .NET libraries and the potential for Native AOT compilation, leading to dramatic performance improvements! Stay tuned for further developments as this project forges a new path!

See you again at the end of year.

```go
// fib.aup
func fib(n) {
  if n < 2 {
    return n;
  }
  return fib(n - 2) + fib(n - 1)
}
```

```cs
// fib.aup.cs
l0_fib_00be8d5a = Value.Function((Value[] p_00f37a0e) =>
{
  Value l0_n_00fa30f4 = p_00f37a0e[0];
  if (((bool)((l0_n_00fa30f4).__lt_cond(2D))))
  {
    return l0_n_00fa30f4;
  }
  return (l0_fib_00be8d5a.__call((l0_n_00fa30f4).__sub(2D))).__add(l0_fib_00be8d5a.__call((l0_n_00fa30f4).__sub(1D)));
});
```

> `Value` is a NaN number, a runtime value. 
