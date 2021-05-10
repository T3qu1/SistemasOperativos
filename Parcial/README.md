# Cena de los filosofos comensales
Para realizar este problema se debe tener en cuenta las siguientes condiciones:\

:pushpin:El usuario tiene la posibilidad de crear N filósofos.\
:pushpin:Un filósofo es un hilo(thread) que se ejecuta de manera independiente.\
:pushpin:Existe un recurso preciado que son los tenedores que tienen a cada lado.\
:pushpin:Cada filósofo comienza pensando y luego tiene hambre, en ese momento pregunta por el estado de sus tenedores contiguos (izquierda y derecha) si coge los dos
  tenedores entonces comienza a comer por un tiempo determinado(aleatorio).\
:pushpin:Cada filosofo tiene un estómago que debe controlar al comer. Un filósofo debe irse a pensar cuando llena su estómago. Cuando un filósofo piensa consume energía 
  por lo tanto disminuye su estómago. También, se debe determinar una variable para representar el total de la comida.\
:pushpin:Un filósofo puede pasar un tiempo determinado de hambre, pasando ese tiempo muere por falta de comida.\

Se puede utilizar los lenguajes de C y C++

Al realizar este problema se tomo como referencia el siguiente [codigo](https://github.com/AndreyArguedas/Dinning-philosophers/blob/master/filosofos.c).
