#!/usr/bin/env bash

VENV_DIR="venv"
REQUIREMENTS_DEV="requirements-dev.txt"

if [ ! -d "$VENV_DIR" ]; then
    echo "Creating virtual environment..."
    python3 -m venv "$VENV_DIR"
    "$VENV_DIR/bin/pip" install -r "$REQUIREMENTS_DEV"
fi

source "$VENV_DIR/bin/activate"

echo "🛠️  Running Ruff (Lint & Format)..."
ruff check --fix *.py
ruff format *.py

