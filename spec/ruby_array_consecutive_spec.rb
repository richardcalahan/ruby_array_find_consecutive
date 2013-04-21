require 'spec_helper'
require 'ruby_array_find_consecutive'

describe Array do 
  it 'finds 1 array of consecutive integers incrementing by 1' do
    [1, 2, 3].find_consecutive.length.should == 1
  end

  it 'finds 2 arrays of consecutive integers incrementing by 1' do
    [1, 2, 3, 5, 4, 5, 6].find_consecutive.length.should == 2
  end

  it 'finds 1 array of consecutive integers incrementing by 2' do
    [1, 3, 5, 7, 9].find_consecutive(2).length.should == 1
  end

  it 'finds 2 arrays of consecutive integers incrementing by 2' do
    [1, 3, 5, 7, 9, 3, 5, 7, 9, 11].find_consecutive(2).length.should == 2
  end

  it 'finds 1 array of consecutive integers incrementing by 1.5' do
    [0, 1.5, 3, 4.5, 6].find_consecutive(1.5).length.should == 1
  end

  it 'finds 2 arrays of consecutive integers incrementing by 1.5' do
    [0, 1.5, 3, 4.5, 6, 3, 4.5].find_consecutive(1.5).length.should == 2
  end

  it 'finds 0 arrays of consecutive integers incrementing 1' do
    [0, 1.5, 3, 4.5, 6, 3, 4.5].find_consecutive(1).length.should == 0
  end
end
