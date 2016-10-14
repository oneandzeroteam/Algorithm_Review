class TestCase
  def initialize(quadtree)
    @quadtree = quadtree.gsub("\n","").split('')
  end

  # Check for exceptions and pre-process the Array
  def process
    if @quadtree.first() == "w" or @quadtree.first() == "b"
      return @quadtree.flatten.join("")
    else
      @quadtree.shift()
      return recurisve.flatten.join("")
    end
  end

  # Recurisve function for tree iteration
  def recurisve
    list = []
    (1..4).each do |i|
      e = @quadtree.shift()
      e = recurisve if e == 'x'
      list << e
    end
    return reverse(list)
  end

  # Returns a reversed array
  def reverse(list)
    return ["x"] + list.pop(2) + list
  end
end

input = $stdin.readlines
number_of_test_cases = input.shift.to_i
output = []

(1..number_of_test_cases).each do |index|
  test_case_input = input.shift()
  t = TestCase.new(test_case_input)
  puts t.process
end
