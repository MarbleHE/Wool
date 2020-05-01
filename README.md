# Wool


## Getting Started

### Wool Library

Set up the ready-to-go development environment using Docker as follow:

```
docker pull marblehe/wool_library
docker tag marblehe/wool_library wool_library
git clone https://github.com/MarbleHE/Wool
cd Wool
docker build -t wool_library_ssh -f Dockerfile_wool_library_ssh .
docker run -d --cap-add sys_ptrace -p 127.0.0.1:2222:22 wool_library_ssh
```

Afterwards, configure a remote toolchain in the IDE of your choice (for example, CLion) using the SSH credentials: `user:password@127.0.0.1:2222`.


### Wool development


```
docker pull marblehe/wool_base
docker tag marblehe/wool_base wool_base
git clone https://github.com/MarbleHE/Wool
cd Wool
docker build -t wool_base_ssh -f Dockerfile_wool_base_ssh .
docker run -d --cap-add sys_ptrace -p 127.0.0.1:2222:22 wool_base_ssh
```

Afterwards, configure a remote toolchain in the IDE of your choice (for example, CLion) using the SSH credentials: `user:password@127.0.0.1:2222`.
