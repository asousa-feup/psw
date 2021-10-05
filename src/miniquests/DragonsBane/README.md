# DragonsBane

The mini-quest "Dragon's Bane" is supposed to reuse the results from mini-quest
I "Here Be Dragons". Concepts such as classes and objects should be used for
implementing the mini-quest. This mini-quest is implemented in C++ and was
compiled in VS Code. See the [`guide`](doc/lprog_mini-quest-2_dragons-bane.pdf)
for more information about the mini-quest.

Only the common part of the mini-quest is implemented in C++, just as in the
Java version. The videos available for the Java version are the following ones:

- Package separation ([video](https://www.youtube.com/watch?v=ob-8gabEB_M))
- New Game Logic ([video](https://www.youtube.com/watch?v=GcybhYNrOo8))
- Dragon movement and multiple dragons
  ([video](https://www.youtube.com/watch?v=TfEQHLTe3_E))

The YouTube video for the Java version is also valid for C++. You should have
the following considerations in C++:

- Namespaces:
  - Consider equivalent to packages in Java
  - Separate different namespaces in different folders insider `src/` and
    `include/`
- Classes: usually, separate different classes in different `cpp/h` files

## Get started

### Compile and run the program

1. Terminal > Run Task... (optional)
   - Select `'Build DragonsBane'`
   - Analyze the `tasks.json` file for evaluating the structure of these types
     of files (possiblity of defining dependencies, parallel tasks, etc.)
2. Run > Start Debugging OR Run Without Debugging
