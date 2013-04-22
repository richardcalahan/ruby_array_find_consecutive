## C extension for Ruby: Array#find_consecutive

### Description
   
`Array#find_consecutive` is a C extension for Ruby. It returns an array of non-overlapping arrays of consecutive numbers for `self` for a given interval. If no interval argument is provided the default is 1. You can optionally pass a block that will be yielded each array of consecutive numbers. That's a mouthful, so perhaps an example will help.

### Usage

```

[1, 2, 3, 4, 5].find_consecutive
# => [[1, 2, 3, 4, 5]]

[1, 2, 3, 4, 5, 10, 4, 5, 6, 7, 8].find_consecutive
# => [[1, 2, 3, 4, 5], [4, 5, 6, 7, 8]]

[1, 2, 3, 4, 6, 8, 10, 12, 14].find_consecutive(2)
# => [[4, 6, 8, 10, 12, 14]]

[1, 2, 3.5, 5, 6.5, 8, 9, 10, 11.5, 13].find_consecutive(1.5)
# => [[2, 3.5, 5, 6.5, 8], [10, 11.5, 13]]

[1, 2, 3, 4, 7, 6, 7, 8, 9, 10].find_consecutive do |ary|
    puts ary.length
end

# => 4
# => 5
# => [[1, 2, 3, 4], [6, 7, 8, 9, 10]]

```

### And...it's fast!

The benchmark suite interates an array of length > 2,000,000 using the C extension and a pure Ruby implementation.

```

$ ./benchmark
                                               user     system      total        real
find_consecutive C    (integer interval)   0.460000   0.000000   0.460000 (  0.459470)
find_consecutive Ruby (integer interval)   1.030000   0.000000   1.030000 (  1.030171)
find_consecutive C    (float interval)     0.390000   0.000000   0.390000 (  0.394497)
find_consecutive Ruby (float interval)     1.500000   0.010000   1.510000 (  1.506115)   

```
   
### Installation

Add this line to your application's Gemfile:

    gem 'ruby_array_find_consecutive'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install ruby_array_find_consecutive
