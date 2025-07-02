# Insights 

## Json style 
### Base path
the ideia is just have a simple way to fast get the new json object in the right way and not need specify the every object path in json

It`s in the start of json and looks like this: 
```
base_path= *Just the base path of object*
```

### Object to be saved 

In that part conatins the objects and values to be added in i18n archives. The path ensured in that part completes the path specified in base path. In the values the base pattern is(de, en, es,fr,it,pt), thinking it`s a good idea make possible custom patterns

Example: 
```
"host": {
  "common": {
    "header": {
      "hello": ("Hallo, ", "Hello, ", "Hola, ", "Bonjour, ", "Ciao, ", "Olá, "),
      "announce": (
        "RAUM ANBIETEN",       // Alemão
        "OFFER SPACE",         // Inglês
        "OFRECER ESPACIO",     // Espanhol
        "PROPOSER UN ESPACE",  // Francês
        "OFFRI SPAZIO",        // Italiano
        "ANUNCIAR ESPAÇO"      // Português
      ),
      "find": {
        "space": (
          "RAUM FINDEN",       // Alemão
          "FIND SPACE",        // Inglês
          "ENCONTRAR ESPACIO", // Espanhol
          "TROUVER UN ESPACE", // Francês
          "TROVA SPAZIO",      // Italiano
          "ENCONTRAR ESPAÇO"   // Português
        ),
        !override // <- says that value override a existing value in i18n objects
        "login": (
          "ANMELDEN",           // Alemão
          "LOGIN",              // Inglês
          "INICIAR SESIÓN",     // Espanhol
          "SE CONNECTER",       // Francês
          "ACCEDI",             // Italiano
          "ENTRAR"              // Português
        )
      }
    }
  }
}

```