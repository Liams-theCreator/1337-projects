# Glossary

[← Back to repository overview](./README.md)

Terminology shared across the projects in this repository.

## C and memory

**libft** — The custom C library written in [`libft`](./libft) and reused by nearly every
later project; see [`libft/README.md`](./libft/README.md).

**Static variable** — A variable whose lifetime spans the whole program but whose scope is
limited to a function or file. `get_next_line` uses one to keep the unread remainder of a
file descriptor between calls.

**File descriptor** — A small integer identifying an open file, pipe or socket. `0`, `1`
and `2` are standard input, output and error.

**Variadic function** — A function taking a variable number of arguments, accessed through
`va_start` / `va_arg` / `va_end`; the basis of `ft_printf`.

**Dangling pointer** — A pointer to memory that has already been freed. Avoided in these
projects by setting pointers to `NULL` after freeing (see `freeing()` in `get_next_line`).

**Garbage collector** — In `minishell`, the `t_collector` list that records every
allocation so an entire command's memory can be released with a single call
(`free_collector_all`).

## Processes and shells

**fork / execve** — `fork` duplicates the current process; `execve` replaces the process
image with a new program. Together they run external commands from a shell.

**Pipe** — A unidirectional kernel buffer connecting the standard output of one process to
the standard input of another, created with `pipe` and wired with `dup2`.

**Redirection** — Rebinding a file descriptor to a file: `<`, `>`, `>>` and heredoc `<<`.

**Heredoc** — An inline input block read until a delimiter line; its content is expanded
unless the delimiter is quoted.

**Lexer / Parser** — The lexer turns raw input into tokens (words, pipes, redirection
operators); the parser groups those tokens into commands with their arguments and
redirections.

**Builtin** — A command implemented inside the shell rather than as an external binary:
`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.

**Exit status** — The value returned by the last command, exposed as `$?`. `127` means
command not found, `126` not executable, `130` interrupted by `SIGINT`.

**UNIX signal** — An asynchronous notification delivered to a process. `mini_talk` uses
`SIGUSR1` and `SIGUSR2` as a one-bit transmission channel; standard signals are not queued,
which is why the sender throttles itself.

## Concurrency

**Thread** — An independent execution flow sharing the address space of its process,
created with `pthread_create`.

**Mutex** — A lock guaranteeing that only one thread at a time accesses a shared resource
(`pthread_mutex_lock` / `unlock`).

**Race condition** — A bug where the result depends on the unpredictable interleaving of
threads; prevented by protecting every shared field with a mutex.

**Deadlock** — A state in which threads wait on each other forever. In `Philosophers` it is
avoided by making even- and odd-numbered philosophers pick up their forks in opposite
order.

**Circular wait** — The condition where each thread holds one resource and waits for the
next one in a cycle; one of the four necessary conditions for deadlock.

**Starvation** — A thread that never gets access to a resource. In `Philosophers` it is
detected by the watcher thread as a death.

## Graphics

**MiniLibX (MLX)** — The minimal graphics library provided by 42: window creation, image
buffers, XPM loading, key and event hooks.

**XPM** — A plain-text image format used for the textures in `so_long` and `cub3d`.

**Ray casting** — Rendering a pseudo-3D view by casting one ray per screen column and
drawing a wall slice whose height is inversely proportional to the distance hit.

**DDA (Digital Differential Analyzer)** — The grid traversal algorithm that steps a ray
from one map cell boundary to the next until it hits a wall.

**Camera plane** — The vector perpendicular to the view direction whose length sets the
field of view (`0.66` ≈ 66° in `cub3d`).

**Flood fill** — Recursive area filling used in `so_long` to prove that every collectible
and the exit are reachable from the player's starting tile.

## Networking and systems

**Subnet mask** — A 32-bit bitmask splitting an IPv4 address into a network part and a host
part.

**CIDR** — Notation writing a mask as a prefix length, e.g. `/24` for `255.255.255.0`.

**Default gateway** — The next-hop router used for any destination outside the local
subnet; it must be an address inside that subnet.

**NAT** — Network Address Translation: rewriting private addresses into a public one at the
network edge.

**Switch vs. router** — A switch forwards frames within one subnet (layer 2); a router
forwards packets between subnets (layer 3).

**LVM** — Logical Volume Manager: Physical Volumes are pooled into Volume Groups from which
resizable Logical Volumes are carved.

**SSH** — Encrypted remote shell protocol; in `Born2beRoot` it runs on port `4242` with
root login disabled.

**UFW** — Uncomplicated Firewall, the front-end used to deny all incoming traffic except
the allowed port.

## C++

**Orthodox canonical form** — The four members every C++98 class should define: default
constructor, copy constructor, copy assignment operator and destructor.

**Deep copy** — Duplicating the memory owned by an object rather than copying the pointer,
required whenever a class allocates with `new`.

**Polymorphism** — Calling a derived implementation through a base-class pointer or
reference, enabled by `virtual` member functions.

**Abstract class** — A class with at least one pure virtual function (`= 0`) that cannot be
instantiated, e.g. `AbsAnimal` and `AMateria`.

**Interface** — A class with only pure virtual functions and no state, e.g. `ICharacter`
and `IMateriaSource`.
