#! /bin/bash

# This script runs clang-tidy on its input arguments with all of clang-tidy's
# flags set up nicely.

set -euo pipefail

usage() {
	echo "usage: run_clang_tidy.sh <cc file>..."
}

# http://stackoverflow.com/a/17841619/3187068
join() {
	local IFS=","
	echo "$*"
}

main() {
	if [[ $# -eq 0 ]]; then
		usage
		return 64
	fi

	local project_directory
	project_directory="$(dirname "$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )")"

	if [ ! -d "${project_directory}/build" ]; then
		printf "%s/build/ doesn't exist\n" "${project_directory}"
		printf "you must build the project first using %s/scripts/build_debug.sh or %s/scripts/build_release.sh\n\n" "${project_directory}" "${project_directory}"
		usage
		return 64
	fi

	# Arguments for the `-checks` flag.
	checks=()
	checks+=('*')
	checks+=('-llvm-header-guard')
	checks+=('-llvm-include-order')
	# Using googletest macros like EXPECT_EQ trigger this check.
	checks+=('-cppcoreguidelines-pro-type-vararg')


	# Argument for the header-filter command. We want to run clang-tidy on all
	# of our header files, but not on any of the system header files. We also
	# do not want to run clang-tidy on any of the generated protobuf headers.
	local header_filter="^${project_directory}/src"


	exec clang-tidy \
		-checks="$(join "${checks[@]}")" \
		-header-filter="$header_filter" \
		-p "${project_directory}/build" \
		"$@"
}

main "$@"
