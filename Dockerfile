FROM ubuntu:22.04

# Éviter les prompts interactifs
ENV DEBIAN_FRONTEND=noninteractive

# Installer les dépendances
RUN apt-get update && apt-get install -y \
    build-essential \
    make \
    gcc \
    git \
    xorg \
    libx11-dev \
    libxext-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxrender-dev \
    libxfixes-dev \
    x11-apps \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /Fract-ol

# Copier le projet
COPY . .

# Compiler le projet
RUN make

# Commande par défaut : lancer le programme
CMD ["./fract-ol"]
