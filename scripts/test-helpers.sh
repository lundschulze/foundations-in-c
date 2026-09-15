#!/usr/bin/env bash

check_case()
{
    case_name=$1
    program=$2
    expected_status=$3
    input=$4
    expected_output=$5

    set +e
    actual_output=$(printf '%b' "$input" | "$program" 2>&1)
    actual_status=$?
    set -e

    if [ "$actual_status" -ne "$expected_status" ]
    then
        printf '[fail] %s: expected status %s, received %s\n' \
            "$case_name" "$expected_status" "$actual_status" >&2
        return 1
    fi

    if [ "$actual_output" != "$expected_output" ]
    then
        printf '[fail] %s: output differed\n' "$case_name" >&2
        printf '%s\n%s\n' '--- expected' "$expected_output" >&2
        printf '%s\n%s\n' '--- actual' "$actual_output" >&2
        return 1
    fi

    printf '[pass] %s\n' "$case_name"
}

check_pattern()
{
    case_name=$1
    program=$2
    expected_status=$3
    input=$4
    expected_pattern=$5

    set +e
    actual_output=$(printf '%b' "$input" | "$program" 2>&1)
    actual_status=$?
    set -e

    if [ "$actual_status" -ne "$expected_status" ]
    then
        printf '[fail] %s: expected status %s, received %s\n' \
            "$case_name" "$expected_status" "$actual_status" >&2
        return 1
    fi

    if [[ ! "$actual_output" =~ $expected_pattern ]]
    then
        printf '[fail] %s: output did not match the expected pattern\n' "$case_name" >&2
        printf '%s\n%s\n' '--- actual' "$actual_output" >&2
        return 1
    fi

    printf '[pass] %s\n' "$case_name"
}

check_file()
{
    case_name=$1
    path=$2
    expected_content=$3

    if [ ! -f "$path" ]
    then
        printf '[fail] %s: %s was not created\n' "$case_name" "$path" >&2
        return 1
    fi

    actual_content=$(< "$path")
    if [ "$actual_content" != "$expected_content" ]
    then
        printf '[fail] %s: file contents differed\n' "$case_name" >&2
        printf '%s\n%s\n' '--- expected' "$expected_content" >&2
        printf '%s\n%s\n' '--- actual' "$actual_content" >&2
        return 1
    fi

    printf '[pass] %s\n' "$case_name"
}

check_absent()
{
    case_name=$1
    path=$2

    if [ -e "$path" ]
    then
        printf '[fail] %s: %s still exists\n' "$case_name" "$path" >&2
        return 1
    fi

    printf '[pass] %s\n' "$case_name"
}

check_channels()
{
    case_name=$1
    program=$2
    expected_status=$3
    input=$4
    expected_stdout=$5
    expected_stderr=$6
    result_directory=$(mktemp -d)
    stdout_path="$result_directory/stdout"
    stderr_path="$result_directory/stderr"

    set +e
    printf '%b' "$input" | "$program" > "$stdout_path" 2> "$stderr_path"
    actual_status=$?
    set -e

    actual_stdout=$(< "$stdout_path")
    actual_stderr=$(< "$stderr_path")
    rm -f "$stdout_path" "$stderr_path"
    rmdir "$result_directory"

    if [ "$actual_status" -ne "$expected_status" ]
    then
        printf '[fail] %s: expected status %s, received %s\n' \
            "$case_name" "$expected_status" "$actual_status" >&2
        return 1
    fi

    if [ "$actual_stdout" != "$expected_stdout" ]
    then
        printf '[fail] %s: stdout differed\n' "$case_name" >&2
        printf '%s\n%s\n' '--- expected stdout' "$expected_stdout" >&2
        printf '%s\n%s\n' '--- actual stdout' "$actual_stdout" >&2
        return 1
    fi

    if [ "$actual_stderr" != "$expected_stderr" ]
    then
        printf '[fail] %s: stderr differed\n' "$case_name" >&2
        printf '%s\n%s\n' '--- expected stderr' "$expected_stderr" >&2
        printf '%s\n%s\n' '--- actual stderr' "$actual_stderr" >&2
        return 1
    fi

    printf '[pass] %s\n' "$case_name"
}
