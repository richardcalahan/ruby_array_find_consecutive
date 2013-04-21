# Ruby C extension for method Array#consecutive

## Description
   
`Array#consecutive` is a Ruby C extension.    
It returns an array of arrays of consecutive numbers for `self` for a given interval (defaults to 1). That's a mouthful, so perhaps an example will help.

## Usage

```

[1, 2, 3, 4, 5].consecutive
# => [[1, 2, 3, 4, 5]]

[1, 2, 3, 4, 5, 10, 4, 5, 6, 7, 8].consecutive
# => [[1, 2, 3, 4, 5], [4, 5, 6, 7, 8]]

[1, 2, 3, 4, 6, 8, 10, 12, 14].consecutive(2)
# => [[4, 6, 8, 10, 12, 14]]

[1, 2, 3.5, 5, 6.5, 8, 9, 10, 11.5, 13].consecutive(1.5)
# => [[2, 3.5, 5, 6.5, 8], [10, 11.5, 13]]

```

## And...it's fast!

```
                                          user     system      total        real
consecutive c    (integer interval)   0.460000   0.000000   0.460000 (  0.459470)
consecutive ruby (integer interval)   1.030000   0.000000   1.030000 (  1.030171)
consecutive c    (float interval)     0.390000   0.000000   0.390000 (  0.394497)
consecutive ruby (float interval)     1.500000   0.010000   1.510000 (  1.506115)   

```
   
## Installation

Add this line to your application's Gemfile:

    gem 'ruby_array_consecutive'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install ruby_array_consecutive
