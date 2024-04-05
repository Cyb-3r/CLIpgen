# CLI Password Generator (CLIPGen)

## Disclaimer

Using this program to generate passwords is not recommended as the generation algorythm is not safe.
I made this project to learn C, I do not plan on making this usable in the future.

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
