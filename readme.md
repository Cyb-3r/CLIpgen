# CLI Password Generator (CLIPGen)

## Preamble

If this part doesn't interest you, just skip to the Description.

I made this project with the goal of learning to code in C. It is a language that I find pretty interesting due to the fact that if you want, you can build kind of everything with it, and I really like to write code in C overall. I also wanted to learn more about pointers, and this project, despite how simple it may seem, taught me many things about them that I didn't know.

## Disclaimer

Do NOT use this tool to manage your passwords, it's not safe at all because the generation function uses rand(), I would've liked if this project would be able to be used but sadly I'm not experienced enough to garanty a secure password generation.

## Description

This is a simple command line interface password generator.
You can configure few of the returned password's properties.

## Usage

to create a password, use the `create` command.
You can use the following settings :
```
-l  | --length  : sets the password length (int)
-a  | --amount  : tells the generator how much passwords to generate (int)
-n  | --number  : enables numbers (bool)
-s  | --special : enables special chars (bool)
-sv | --saveto  : save to given file path [NOT AVAILABLE YET]
```

### Command example

```bash
clipg create -l 16 -n true -s true
```

## Status

Right now, numbers and special char settings are not entirely stable, 
it works fine with both on but you might not get expected results with
one of them on.

## Todo

- [ ] Upgrade the argument scanner
- [ ] Add a `rate` command that rates the strength of a password
- [ ] Implement functions to save passwords into a file
- [ ] Implement functions to read passwords from a file
- [ ] Add encryption function to save

## Future

Once I'm done with the todo list, I'll probably use that project as a base for a whole local CLI password manager as a fun side project.
Or I could just build a GUI alternative version built ontop of the CLI one's source to make a more graphical password generator.