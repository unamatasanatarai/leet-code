#!/usr/bin/env bash

[[ -z $1 ]] && echo "Usage: $0 file.php" && exit 1

php-cs-fixer fix "$1" --rules=@PSR12
