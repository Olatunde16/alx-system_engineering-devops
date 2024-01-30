#!/usr/bin/env ruby

# Check if an argument is provided
if ARGV.empty?
  puts "Usage: #{$PROGRAM_NAME} <string>"
  exit 1
end

# Extract the argument
input_string = ARGV[0]

# Use the regular expression to find and output the matched phone number or an empty string if no match
puts input_string.scan(/^\d{10}$/).join
