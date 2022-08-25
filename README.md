# philosophers

-------------------------------------------------



>In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to
>illustrate synchronization issues and techniques for resolving them.
>
>Five philosophers dine together at the same table. Each philosopher has their own place at the table. Their
>philosophical problem in this instance is that the dish served is a kind of spaghetti which has to be eaten with two
>forks.
>
>There is a fork between each plate. Each philosopher can alternately think, eat and sleep. Moreover, a philosopher can
>only eat their spaghetti when they have both a left and right fork. Thus two forks will only be available when their
>two nearest neighbors are sleeping or thinking, not eating. After an individual philosopher finishes eating, they will
>put down both forks. The problem is how to design a regimen (a concurrent algorithm) such that no philosopher will
>starve, assuming that no philosopher can know when others may want to eat or think (an issue of incomplete information).

*<p align=right><a href="https://en.wikipedia.org/wiki/Dining_philosophers_problem">Wikipedia</a></p>*
