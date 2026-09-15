# Greeting

`fgets` reads a bounded line and leaves a newline when it fits. `strcspn` locates that newline, which is replaced with the string terminator.

```bash
make greeting
./greeting
```

Enter `Maya`. The complete interaction is:

```text
Your name: Maya
Welcome, Maya.
```

This opening example keeps long-line handling visible as a limitation; the line inspector exercise reports whether the newline fitted.

