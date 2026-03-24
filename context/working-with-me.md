# Working With Me

Guidelines for Claude when working on this project.

## Code

- **Always write C++ code.** Never suggest creating or editing things in Blueprints — even if it would be quicker. The goal is a C++ codebase.
- **Search the web before implementing.** Look up how a feature is typically done in UE5 before writing code. Don't reinvent the wheel — use engine idioms, existing subsystems, and established patterns.

## Communication

- Keep responses concise and direct.
- Lead with the action or answer, not the reasoning.
- No trailing summaries — the user can read the diff/output.

## Project Context

- UE 5.6, C++ code project
- Module: `test_claude_01`
- See `context/project-overview.md` for full project structure
- See `context/build-and-launch.md` for build commands

## Version Control

- Git repo connected to GitHub: `git@github.com:gunshot8000-creator/test_claude_01.git`
- SSH auth (key at `~/.ssh/id_ed25519`)
- Git identity: Haitham / Gunshot8000@gmail.com
- Content/ is tracked in git (no LFS)
