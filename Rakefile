require 'rake'
require 'rake/clean'

NAME    = 'css'
RELEASE = '0.0.1'

def library (name)
    return "lib#{name}.so"
end

CC = 'clang'

OPTIONS = '-Os -Wall -Wextra -Wno-long-long -pedantic'

if ENV['DEBUG']
    OPTIONS << ' -g3'
end

CFLAGS  = "#{OPTIONS} #{`pcre-config --cflags`.strip} -Iinclude"
LDFLAGS = "#{`nspr-config --libs`.strip} #{`pcre-config --libs`.strip}"

SOURCES = FileList['sources/**/*.c']

if ENV['SELECTOR']
    CFLAGS  << " #{`xml2-config --cflags`.strip}"
    LDFLAGS << " #{`xml2-config --libs`.strip}"
else
    SOURCES.exclude('sources/selector/**')
end

OBJECTS = SOURCES.ext('o')

CLEAN.include(OBJECTS)
CLOBBER.include(library(NAME))

task :default => library(NAME)

task :compile => OBJECTS

rule '.o' => '.c' do |t|
    sh "#{CC} -fPIC #{CFLAGS} -o #{t.name} -c #{t.source}"
end

task :config do
    file = File.open('css-config', 'w')

    file.write <<CONFIG
#! /bin/sh

PREFIX='/usr'
LIBRARY_NAME='wrong'

usage()
{
	cat <<EOF
Usage: wrong-config [OPTIONS]
Options:
	[--libs]
	[--cflags]
EOF
	exit $1
}

if test $# -eq 0; then
	usage 1 1>&2
fi

while test $# -gt 0; do
  case "$1" in
  -*=*) optarg=`echo "$1" | sed 's/[-_a-zA-Z0-9]*=//'` ;;
  *) optarg= ;;
  esac

  case $1 in
    --cflags)
      echo_cflags=yes
      ;;
    --libs)
      echo_libs=yes
      ;;
    *)
      usage 1 1>&2
      ;;
  esac
  shift
done

if [[ $echo_cflags ]]; then
    echo "-I$PREFIX/include #{'$(xml2-config --cflags)' if ENV['SELECTOR']}"
fi

if [[ $echo_libs ]]; then
    echo "-L$PREFIX/lib -lcss"
fi

CONFIG

    file.close
end

file library(NAME) => :compile do
    sh "#{CC} #{OPTIONS} -dynamiclib -shared -Wl,-soname,#{library(NAME)} -o #{library(NAME)} #{OBJECTS} #{LDFLAGS}"
end

task :documentation do
    doxygen .doxygen
end
